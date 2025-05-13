#ifndef DATABASE_HXX
#define DATABASE_HXX

#include <List.hxx>
#include <Article.hxx>
#include <Filer.hxx>
#include <map>
#include <iostream>
#include <Crypter.hxx>
#include <set>

class Database {
protected:
    Filer file;
    std::string filename;
    std::string filename_enc;
    List<Article> data;
    Crypter crypter;
public:
    Database();
    Database(const std::string& filename);
    Database(const List<Article>& articles, const std::string& filename);
    Database(const Database& db);
    ~Database();

    Database& operator=(const Database& db) noexcept;
    Article& operator[](unsigned int index) noexcept;
    const Article& operator[](unsigned int index) const noexcept;
    friend std::ostream& operator<<(std::ostream& os, const Database& db);

    void append(const Article& article) noexcept;
    void remove(unsigned int index) noexcept;
    unsigned int size() const noexcept;

    List<Article> getArticlesBySubject(const std::string& subject) const noexcept;
    List<Article> getJournalsByDepartment(const std::string& department) const noexcept;
    unsigned int countSubjectsWithVakJournals() const noexcept;
};

#endif // DATABASE_HXX
