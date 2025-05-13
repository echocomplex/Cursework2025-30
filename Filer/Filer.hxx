#ifndef FILER_HXX
#define FILER_HXX

#include <string>
#include <mutex>
#include <fstream>
#include <List.hxx>
#include <Article.hxx>

class Filer {
private:
    std::string path;
    std::mutex mutex;

public:
    Filer() noexcept = default;
    Filer(const std::string& path, bool createNew = false);
    ~Filer() noexcept = default;

    void open(const std::string& path, bool createNew = false);
    void read(std::string& str);
    void readToList(List<Article>& articles);
    void writeBack(std::string& str);
    void writeBackFromArticle(const Article& article);
    void rewrite(std::string& str);
    void rewriteFromList(const List<Article>& articles);

    static void stringToArticle(Article& article, const std::string& str);
};

#endif // FILER_HXX
