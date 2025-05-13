#include "Article.hxx"

Article::Article(const std::string& recId,
                 const std::string& author,
                 const std::string& title,
                 const std::string& journal,
                 const std::string& status,
                 const std::string& instCode,
                 const std::string& deptCode,
                 const std::string& subject,
                 const std::string& topic) noexcept
    : recordId(recId), authorName(author), articleTitle(title),
      journalNameNumber(journal), journalStatus(status),
      instituteCode(instCode), departmentCode(deptCode),
      subjectName(subject), topicName(topic) {}

std::string Article::getRecordId() const noexcept { return recordId; }
std::string Article::getAuthorName() const noexcept { return authorName; }
std::string Article::getArticleTitle() const noexcept { return articleTitle; }
std::string Article::getJournalNameNumber() const noexcept { return journalNameNumber; }
std::string Article::getJournalStatus() const noexcept { return journalStatus; }
std::string Article::getInstituteCode() const noexcept { return instituteCode; }
std::string Article::getDepartmentCode() const noexcept { return departmentCode; }
std::string Article::getSubjectName() const noexcept { return subjectName; }
std::string Article::getTopicName() const noexcept { return topicName; }

void Article::setRecordId(const std::string& recId) noexcept { recordId = recId; }
void Article::setAuthorName(const std::string& author) noexcept { authorName = author; }
void Article::setArticleTitle(const std::string& title) noexcept { articleTitle = title; }
void Article::setJournalNameNumber(const std::string& journal) noexcept { journalNameNumber = journal; }
void Article::setJournalStatus(const std::string& status) noexcept { journalStatus = status; }
void Article::setInstituteCode(const std::string& code) noexcept { instituteCode = code; }
void Article::setDepartmentCode(const std::string& code) noexcept { departmentCode = code; }
void Article::setSubjectName(const std::string& subject) noexcept { subjectName = subject; }
void Article::setTopicName(const std::string& topic) noexcept { topicName = topic; }

Article& Article::operator=(const Article& other) noexcept {
    if (this != &other) {
        recordId = other.recordId;
        authorName = other.authorName;
        articleTitle = other.articleTitle;
        journalNameNumber = other.journalNameNumber;
        journalStatus = other.journalStatus;
        instituteCode = other.instituteCode;
        departmentCode = other.departmentCode;
        subjectName = other.subjectName;
        topicName = other.topicName;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Article& article) {
    os << "Record ID: " << article.recordId << "\n"
       << "Author: " << article.authorName << "\n"
       << "Title: " << article.articleTitle << "\n"
       << "Journal: " << article.journalNameNumber << "\n"
       << "Status: " << article.journalStatus << "\n"
       << "Institute: " << article.instituteCode << "\n"
       << "Department: " << article.departmentCode << "\n"
       << "Subject: " << article.subjectName << "\n"
       << "Topic: " << article.topicName;
    return os;
}
