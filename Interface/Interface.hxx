#ifndef INTERFACE_HXX
#define INTERFACE_HXX

#include <iostream>
#include <Article.hxx>
#include <List.hxx>
#include <Database.hxx>
#include <set>

class Interface {
private:
    Database db;
    void displayMenu();
    void getArticle(Article& article);
    int removeArticle();
    void clearInputBuffer();
    void displayArticles(const List<Article>& articles);
public:
    Interface() = default;
    Interface(const Interface&) = delete;
    Interface& operator=(const Interface&) = delete;
    ~Interface() noexcept = default;
    void run();
};

#endif // INTERFACE_HXX