#ifndef ARTICLE_HXX
#define ARTICLE_HXX

#include <string>
#include <iostream>

class Article {
private:
    std::string recordId;
    std::string authorName;
    std::string articleTitle;
    std::string journalNameNumber;
    std::string journalStatus;
    std::string instituteCode;
    std::string departmentCode;
    std::string subjectName;
    std::string topicName;

public:
    Article() noexcept = default;
    Article(const std::string& recId,
            const std::string& author,
            const std::string& title,
            const std::string& journal,
            const std::string& status,
            const std::string& instCode,
            const std::string& deptCode,
            const std::string& subject,
            const std::string& topic) noexcept;

    std::string getRecordId() const noexcept;
    std::string getAuthorName() const noexcept;
    std::string getArticleTitle() const noexcept;
    std::string getJournalNameNumber() const noexcept;
    std::string getJournalStatus() const noexcept;
    std::string getInstituteCode() const noexcept;
    std::string getDepartmentCode() const noexcept;
    std::string getSubjectName() const noexcept;
    std::string getTopicName() const noexcept;

    void setRecordId(const std::string& recId) noexcept;
    void setAuthorName(const std::string& author) noexcept;
    void setArticleTitle(const std::string& title) noexcept;
    void setJournalNameNumber(const std::string& journal) noexcept;
    void setJournalStatus(const std::string& status) noexcept;
    void setInstituteCode(const std::string& code) noexcept;
    void setDepartmentCode(const std::string& code) noexcept;
    void setSubjectName(const std::string& subject) noexcept;
    void setTopicName(const std::string& topic) noexcept;

    Article& operator=(const Article&) noexcept;
    friend std::ostream& operator<<(std::ostream& os, const Article& article);
};

#endif // ARTICLE_HXX
