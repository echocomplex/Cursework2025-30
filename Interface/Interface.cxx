#include "Interface.hxx"

void Interface::clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Interface::getArticle(Article& article) {
    std::string recId, author, title, journal, status, instCode, deptCode, subject, topic;
    
    std::cout << "\n=== Add New Article ===\n";
    
    std::cout << "Record ID: ";
    std::getline(std::cin, recId);
    
    std::cout << "Author name: ";
    std::getline(std::cin, author);
    
    std::cout << "Article title: ";
    std::getline(std::cin, title);
    
    std::cout << "Journal name and number: ";
    std::getline(std::cin, journal);
    
    std::cout << "Journal status (VAK/other): ";
    std::getline(std::cin, status);
    
    std::cout << "Institute code: ";
    std::getline(std::cin, instCode);
    
    std::cout << "Department code: ";
    std::getline(std::cin, deptCode);
    
    std::cout << "Subject name: ";
    std::getline(std::cin, subject);
    
    std::cout << "Topic name: ";
    std::getline(std::cin, topic);
    
    article = Article(recId, author, title, journal, status, instCode, deptCode, subject, topic);
}

int Interface::removeArticle() {
    int number;
    while (true) {
        std::cout << "Enter article number to delete (1-" << db.size() << "): ";
        
        if (!(std::cin >> number)) {
            std::cin.clear();
            clearInputBuffer();
            std::cerr << "Error: Please enter a number\n\n";
            continue;
        }

        if (number > 0 && number <= db.size()) {
            return number - 1;
        }
        
        std::cerr << "Error: Number must be between 1 and " << db.size() << "\n\n";
    }
}

void Interface::displayArticles(const List<Article>& articles) {
    if (articles.length() == 0) {
        std::cout << "No articles found.\n";
        return;
    }
    
    for (unsigned int i = 0; i < articles.length(); ++i) {
        std::cout << i+1 << ". " << articles[i] << "\n\n";
    }
}

void Interface::displayMenu() {
    std::cout << "\n=== Scientific Articles Database ===" << std::endl;
    std::cout << "1. Display all articles" << std::endl;
    std::cout << "2. Add new article" << std::endl;
    std::cout << "3. Remove article" << std::endl;
    std::cout << "4. Find articles by subject" << std::endl;
    std::cout << "5. Find journals by department" << std::endl;
    std::cout << "6. Count subjects with VAK journals" << std::endl;
    std::cout << "7. Exit program" << std::endl;
    std::cout << "Enter your choice (1-7): ";
}

void Interface::run() {
    short choice = 0;
    Article newArticle;
    List<Article> articles;
    std::string input;
    
    while (true) {
        displayMenu();

        while (!(std::cin >> choice) || choice < 1 || choice > 7) {
            std::cout << "Invalid input. Please enter 1-7: ";
            clearInputBuffer();
        }

        clearInputBuffer();

        switch (choice) {
            case 1:
                std::cout << "\n[All Articles]\n";
                for (unsigned int i = 0; i < db.size(); ++i) {
                    articles.append(db[i]);
                }
                displayArticles(articles);
                articles.clear();
                break;
                
            case 2:
                getArticle(newArticle);
                db.append(newArticle);
                std::cout << "Article added successfully!\n";
                break;
                
            case 3:
                if (db.size() == 0) {
                    std::cout << "No articles to remove.\n";
                    break;
                }
                db.remove(removeArticle());
                std::cout << "Article removed successfully!\n";
                break;
                
            case 4:
                std::cout << "Enter subject name: ";
                std::getline(std::cin, input);
                std::cout << "\n[Articles on subject: " << input << "]\n";
                articles = db.getArticlesBySubject(input);
                displayArticles(articles);
                articles.clear();
                break;
                
            case 5:
                std::cout << "Enter department code: ";
                std::getline(std::cin, input);
                std::cout << "\n[Journals for department: " << input << "]\n";
                articles = db.getJournalsByDepartment(input);
                displayArticles(articles);
                articles.clear();
                break;
                
            case 6:
                std::cout << "\n[Subjects with VAK journals]\n";
                std::cout << "Total: " << db.countSubjectsWithVakJournals() << " subjects\n";
                break;
                
            case 7:
                std::cout << "\nExiting program...\n";
                return;
        }

        std::cout << "\nPress Enter to continue...";
        clearInputBuffer();
    }
}