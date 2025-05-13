#include "Database.hxx"

Database::Database() {
    filename = "database.txt";
    filename_enc = "database.enc";
    crypter.decrypt(filename_enc, filename);
    file.open(filename, true);
    file.readToList(data);
}

Database::Database(const std::string& filename) {
    this->filename = filename + ".txt";
    filename_enc = filename + ".enc";
    crypter.decrypt(filename_enc, this->filename);
    file.open(this->filename);
    file.readToList(data);
}

Database::Database(const List<Article>& articles, const std::string& filename) {
    data = articles;
    this->filename = filename + ".txt";
    filename_enc = filename + ".enc";
    file.open(this->filename);
}

Database::Database(const Database& db) {
    data = db.data;
    filename = db.filename;
    filename_enc = db.filename_enc;
    file.open(filename);
}

Database::~Database() {
    file.rewriteFromList(data);
    crypter.encrypt(filename, filename_enc);
}

Database& Database::operator=(const Database& db) noexcept {
    if (this != &db) {
        data = db.data;
        filename = db.filename;
        filename_enc = db.filename_enc;
        file.open(filename);
    }
    return *this;
}

Article& Database::operator[](unsigned int index) noexcept {
    return data[index];
}

const Article& Database::operator[](unsigned int index) const noexcept {
    return data[index];
}

std::ostream& operator<<(std::ostream& os, const Database& db) {
    for (unsigned int i = 0; i < db.data.length(); ++i) {
        os << i + 1 << ". " << db.data[i] << "\n";
    }
    return os;
}

void Database::append(const Article& article) noexcept {
    data.append(article);
}

void Database::remove(unsigned int index) noexcept {
    data.remove(index);
}

unsigned int Database::size() const noexcept {
    return data.length();
}

List<Article> Database::getArticlesBySubject(const std::string& subject) const noexcept {
    List<Article> result;
    for (unsigned int i = 0; i < data.length(); ++i) {
        if (data[i].getSubjectName() == subject) {
            result.append(data[i]);
        }
    }
    return result;
}

List<Article> Database::getJournalsByDepartment(const std::string& department) const noexcept {
    List<Article> journals;
    for (unsigned int i = 0; i < data.length(); ++i) {
        if (data[i].getDepartmentCode() == department) {
            journals.append(data[i]);
        }
    }
    return journals;
}

unsigned int Database::countSubjectsWithVakJournals() const noexcept {
    std::set<std::string> uniqueSubjects;
    for (unsigned int i = 0; i < data.length(); ++i) {
        if (data[i].getJournalStatus() == "VAK") {
            uniqueSubjects.insert(data[i].getSubjectName());
        }
    }
    return uniqueSubjects.size();
}
