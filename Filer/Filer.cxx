#include "Filer.hxx"

Filer::Filer(const std::string& path, bool createNew) {
    open(path, createNew);
}

void Filer::open(const std::string& path, bool createNew) {
    std::fstream file(path, std::ios::in);
    if (!file.is_open()) {
        if (createNew) {
            std::ofstream createFile(path);
            createFile.close();
        } else {
            throw std::runtime_error("File cannot be opened or does not exist");
        }
    }
    this->path = path;
}

void Filer::read(std::string& str) {
    std::lock_guard<std::mutex> lock(mutex);
    std::ifstream file(path);
    if (!file.is_open()) throw std::runtime_error("File is not open");

    str.clear();
    std::string line;
    while (std::getline(file, line)) {
        str += line + '\n';
    }
}

void Filer::readToList(List<Article>& articles) {
    std::lock_guard<std::mutex> lock(mutex);
    std::ifstream file(path);
    if (!file.is_open()) throw std::runtime_error("File is not open");

    std::string line;
    while (std::getline(file, line)) {
        Article article;
        stringToArticle(article, line);
        articles.append(article);
    }
}

void Filer::writeBack(std::string& str) {
    if (str.empty()) return;

    std::lock_guard<std::mutex> lock(mutex);
    std::ofstream file(path, std::ios::app);
    if (!file.is_open()) throw std::runtime_error("File is not open");

    file << str << '\n';
}

void Filer::writeBackFromArticle(const Article& article) {
    std::lock_guard<std::mutex> lock(mutex);
    std::ofstream file(path, std::ios::app);
    if (!file.is_open()) throw std::runtime_error("File is not open");

    file << article.getRecordId() << "$$"
         << article.getAuthorName() << "$$"
         << article.getArticleTitle() << "$$"
         << article.getJournalNameNumber() << "$$"
         << article.getJournalStatus() << "$$"
         << article.getInstituteCode() << "$$"
         << article.getDepartmentCode() << "$$"
         << article.getSubjectName() << "$$"
         << article.getTopicName() << '\n';
}

void Filer::rewrite(std::string& str) {
    if (str.empty()) return;

    std::lock_guard<std::mutex> lock(mutex);
    std::ofstream file(path, std::ios::trunc);
    if (!file.is_open()) throw std::runtime_error("File is not open");

    file << str << '\n';
}

void Filer::rewriteFromList(const List<Article>& articles) {
    if (articles.length() == 0) return;

    std::lock_guard<std::mutex> lock(mutex);
    std::ofstream file(path, std::ios::trunc);
    if (!file.is_open()) throw std::runtime_error("File is not open");

    for (unsigned int i = 0; i < articles.length(); ++i) {
        const Article& a = articles[i];
        file << a.getRecordId() << "$$"
             << a.getAuthorName() << "$$"
             << a.getArticleTitle() << "$$"
             << a.getJournalNameNumber() << "$$"
             << a.getJournalStatus() << "$$"
             << a.getInstituteCode() << "$$"
             << a.getDepartmentCode() << "$$"
             << a.getSubjectName() << "$$"
             << a.getTopicName() << '\n';
    }
}

void Filer::stringToArticle(Article& article, const std::string& str) {
    std::string fields[9];
    unsigned short count = 0;

    for (size_t i = 0; i < str.size() && count < 9; ++i) {
        if (i + 1 < str.size() && str[i] == '$' && str[i + 1] == '$') {
            ++count;
            ++i;
        } else {
            fields[count] += str[i];
        }
    }

    article.setRecordId(fields[0]);
    article.setAuthorName(fields[1]);
    article.setArticleTitle(fields[2]);
    article.setJournalNameNumber(fields[3]);
    article.setJournalStatus(fields[4]);
    article.setInstituteCode(fields[5]);
    article.setDepartmentCode(fields[6]);
    article.setSubjectName(fields[7]);
    article.setTopicName(fields[8]);
}
