#include "main.cpp"

int main() {
    std::vector<std::string> bolly;
    static std::string path{};
    int m{};
    int n{};
    int t{};
    int l{};
    int c{};
    int h{};
    int element{};
    Book book1{};
    Book book2{};
    Book book3{};
    Book book4{};
    Electronic_resources elc_res{};
    Cons_par_doc pardoc{};
    Unpub_doc unpub{};


    do {
        std::cout << "Введите путь до файла: ";
        std::getline(std::cin, path);
        std::ifstream file(path);
        int p{};

        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                bolly.push_back(line);
            }
            file.close();

            if (bolly.empty()) {
                std::cout << "Файл пустой." << std::endl;
            } else {
                for (const auto& line : bolly) {
                    std::cout << line << std::endl;
                }
                std::cout << "Выберите действие" << std::endl;
                std::cout << "1. Дополнить список" << std::endl;
                std::cout << "2. Создать Новый" << std::endl;
                std::cin >> p;
                switch (p) {
                    case 1:
                        break;
                    case 2:
                        bolly.clear();
                        break;
                }

            }
        } else {
            std::cout << "Не удалось открыть файл." << std::endl;
            return 0;
        }
    } while (false);

    while (true) {
        if (bolly.empty()){
        } else{
            removeNumbering(bolly);
            sort_numbering(bolly);
        }
        std::cout << "Выберите действии" << std::endl;
        std::cout << "1. Добавить " << std::endl;
        std::cout << "2. Просмотреть список" << std::endl;
        std::cout << "3. Удалить элемент" << std::endl;
        std::cout << "4. Cохранить в файл" << std::endl;
        std::cout << "5. Завершить работу" << std::endl;
        std::cin >> m;
        std::cin.ignore();

        switch (m) {
            case 1:
                std::cout << "1. Книги" << std::endl;
                std::cout << "2. Электронные ресурсы" << std::endl;
                std::cout << "3. Составные части документов" << std::endl;
                std::cout << "4. Неопубликованные документы" << std::endl;
                std::cin >> n;
                std::cin.ignore();
                switch (n) {
                    case 1:
                        std::cout << "1. Однотомное издание" << std::endl;
                        std::cout << "2. Многотомные издания" << std::endl;
                        std::cin >> t;
                        std::cin.ignore();
                        switch (t) {
                            case 1:

                                std::cout << "1. Однотомное издание для не более 3 авторов" << std::endl;
                                std::cout << "2. Однотомное издание для более 3 авторов" << std::endl;
                                std::cin >> l;
                                std::cin.ignore();
                                switch (l) {
                                    case 1:
                                        book1.book_embed1(bolly);
                                        break;
                                    case 2:
                                        book2.book_embed2(bolly);
                                        break;
                                }
                                break;
                            case 2:
                                std::cout << "1. Многотомное издание в целом" << std::endl;
                                std::cout << "2. Отдельный том многотомного издания" << std::endl;
                                std::cin >> c;
                                std::cin.ignore();
                                switch (c) {
                                    case 1:
                                        book3.book_embed3(bolly);
                                        break;
                                    case 2:
                                        book4.book_embed4(bolly);
                                        break;}
                        }
                        break;
                    case 2:
                        elc_res.elec_embed(bolly);
                        break;

                    case 3:
                        pardoc.partdoc_embed(bolly);
                        break;
                    case 4:
                        unpub.unpub_embed(bolly);
                        break;
                }
                break;


            case 2:
                removeNumbering(bolly);
                sort_numbering(bolly);
                show(bolly);
                break;
            case 3:
                removeNumbering(bolly);
                sort_numbering(bolly);
                show(bolly);
                std::cout << "Выберите действии" << std::endl;
                std::cout << "1. удалить " << std::endl;
                std::cout << "2. выход в главное меню" << std::endl;
                std::cin >> h;
                switch (h) {
                    case 1:
                        std::cout << "Выберите элемент который хотите удалть" << std::endl;
                        std::cin >> element;
                        delete_elem(bolly, element);
                        std::cout << "элемент успешно удалён" << std::endl;
                    case 2:
                        break;
                }
                break;
            case 4:
                removeNumbering(bolly);
                sort_numbering(bolly);
                save(bolly, path);
                break;

            case 5:
                return 0;
        }
    }
}
