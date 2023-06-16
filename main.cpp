#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

/**
  * @class Book
  *
  * @brief Stores information about the book
  *
  * @details This class accepts and processes bibliographic records of BOOK type
  */
class Book{
public:
    std::string author{};       //Author
    std::string title{};        //Title
    std::string sor{};          //Responsibility
    std::string pub_state{};    //Publication information
    std::string place_of_pub{}; //Place of publication
    std::string pub_house{};    //Publishing house
    std::string year{};         //The year of publishing
    std::string volume{};       //Volume
    std::string num_of_vol{};   //Number of volumes
    std::string series{};       //Series
    std::string des_and_num{};  //Volume designation and number

    /**
      * @brief Formats a string
      *
      * @details One of the options for formatting a single-volume edition. for LESS than 3 authors
      *
      * @param[out] string This string is formatted according to GOST(HSE)
      */
    std::string conclusion_One_volume_edition1(){
        std::ostringstream oss;
        oss<<"1. "<<author<<"."<<title<<"/"<<sor<<". -"<<pub_state<<". -"<<place_of_pub<<": "<<pub_house<<", "<<year<<". -"<<volume<<".";
        std::string result = oss.str();
        return result;
    }

    /**
      * @brief Formats a string
      *
      * @details One of the options for formatting a single-volume edition. for MORE than 3 authors
      *
      * @param[out] string This string is formatted according to GOST(HSE)
      */
    std::string conclusion_One_volume_edition2(){
        std::ostringstream oss;
        oss<<"1. "<<title<<"/"<<sor<<". -"<<pub_state<<". -"<<place_of_pub<<": "<<pub_house<<", "<<year<<". -"<<volume<<".";
        std::string result = oss.str();
        return result;
    }

    /**
      * @brief Formats a string
      *
      * @details One of the options for formatting a multi-volume edition of a publication. for full edition
      *
      * @param[out] string This string is formatted according to GOST(HSE)
      */
    std::string conclusion_Multi_volume_edition1() {
        std::ostringstream oss;
        oss <<"1. "<< author << "." << title << "/" << sor << ". -" << place_of_pub << ": " << pub_house << ", " << year<< ". -" << num_of_vol << ". -" << series << ".";
        std::string result = oss.str();
        return result;
    }

    /**
      * @brief Formats a string
      *
      * @details One of the options for formatting a multi-volume edition of a publication. for individual volumes
      *
      * @param[out] string This string is formatted according to GOST(HSE)
      */
    std::string conclusion_Multi_volume_edition2(){
        std::ostringstream oss;
        oss<<"1. "<<author<<"."<<title<<"."<<des_and_num<<"/"<<sor<<". -"<<place_of_pub<<": "<<pub_house<<", "<<year<<"-"<<volume<<". -"<< series << ".";
        std::string result = oss.str();
        return result;
    }

    /**
      * @brief Collects information
      *
      * @details Collects information by asking the user for it and adds a new element to the list vector.This is a function for a one-volume edition, for LESS than 3 people
      *
      * @param[in] vector Accepts a vector in which the formatted string will be embedded later
      */
    void book_embed1(std::vector<std::string>& a) {
        int b{};
        std::cout << "Напишите автора" << std::endl;
        std::getline(std::cin, author);
        std::cout << "Заглавие" << std::endl;
        std::getline(std::cin, title);
        std::cout << "Cведения об ответственности" << std::endl;
        std::getline(std::cin, sor);
        std::cout << "Сведения об изданиии" << std::endl;
        std::getline(std::cin, pub_state);
        std::cout << "Место издания" << std::endl;
        std::getline(std::cin, place_of_pub);
        std::cout << "Издательство" << std::endl;
        std::getline(std::cin, pub_house);
        std::cout << "Год издания" << std::endl;
        std::getline(std::cin, year);
        std::cout << "Объем" << std::endl;
        std::getline(std::cin, volume);
        std::cout << conclusion_One_volume_edition1() <<std::endl;
        std::cout << "Выберите действие" << std::endl;
        std::cout << "1. Сохранить" << std::endl;
        std::cout << "2. НЕ сохранять" << std::endl;
        std::cin>>b;
        switch (b) {
            case 1:
                a.push_back(conclusion_One_volume_edition1());
                break;
            case 2:
                break;
        }
    }

    /**
      * @brief Collects information
      *
      * @details Collects information by asking the user for it and adds a new element to the list vector.This is a function for a one-volume edition, for MORE than 3 people
      *
      * @param[in] vector Accepts a vector in which the formatted string will be embedded later
      */
    void book_embed2(std::vector<std::string>& a) {
        int b{};
        std::cout << "Заглавие" << std::endl;
        std::getline(std::cin, title);
        std::cout << "Cведения об ответственности(Авторы)" << std::endl;
        std::getline(std::cin, sor);
        std::cout << "Сведения об изданиии" << std::endl;
        std::getline(std::cin, pub_state);
        std::cout << "Место издания" << std::endl;
        std::getline(std::cin, place_of_pub);
        std::cout << "Издательство" << std::endl;
        std::getline(std::cin, pub_house);
        std::cout << "Год издания" << std::endl;
        std::getline(std::cin, year);
        std::cout << "Объем" << std::endl;
        std::getline(std::cin, volume);
        std::cout << conclusion_One_volume_edition2() <<std::endl;
        std::cout << "Выберите действие" << std::endl;
        std::cout << "1. Сохранить" << std::endl;
        std::cout << "2. НЕ сохранять" << std::endl;
        std::cin>>b;
        switch (b) {
            case 1:
                a.push_back(conclusion_One_volume_edition2());
                break;
            case 2:
                break;
        }
    }

    /**
      * @brief Collects information
      *
      * @details Collects information by asking the user for it and adds a new element to the list vector.This is a function for a multi-volume edition, for whole edition
      *
      * @param[in] vector Accepts a vector in which the formatted string will be embedded later
      */
    void book_embed3(std::vector<std::string>& a) {
        int b{};
        std::cout << "Напишите автора" << std::endl;
        std::getline(std::cin, author);
        std::cout << "Заглавие" << std::endl;
        std::getline(std::cin, title);
        std::cout << "Cведения об ответственности" << std::endl;
        std::getline(std::cin, sor);
        std::cout << "Место издания" << std::endl;
        std::getline(std::cin, place_of_pub);
        std::cout << "Издательство" << std::endl;
        std::getline(std::cin, pub_house);
        std::cout << "Год издания" << std::endl;
        std::getline(std::cin, year);
        std::cout << "Кол-во томов" << std::endl;
        std::getline(std::cin, num_of_vol);
        std::cout << "Серия" << std::endl;
        std::getline(std::cin, series);
        std::cout << conclusion_Multi_volume_edition1() <<std::endl;
        std::cout << "Выберите действие" << std::endl;
        std::cout << "1. Сохранить" << std::endl;
        std::cout << "2. НЕ сохранять" << std::endl;
        std::cin>>b;
        switch (b) {
            case 1:
                a.push_back(conclusion_Multi_volume_edition1());
                break;
            case 2:
                break;
        }
    }

    /**
    * @brief Collects information
    *
    * @details Collects information by asking the user for it and adds a new element to the list vector.This is a function for a multi-volume edition, for separate volume
    *
    * @param[in] vector Accepts a vector in which the formatted string will be embedded later
    */
    void book_embed4(std::vector<std::string>& a) {
        int b{};
        std::cout << "Напишите автора" << std::endl;
        std::getline(std::cin, author);
        std::cout << "Заглавие" << std::endl;
        std::getline(std::cin, title);
        std::cout << "Обозначение и номер тома" << std::endl;
        std::getline(std::cin, des_and_num);
        std::cout << "Cведения об ответственности" << std::endl;
        std::getline(std::cin, sor);
        std::cout << "Место издания" << std::endl;
        std::getline(std::cin, place_of_pub);
        std::cout << "Издательство" << std::endl;
        std::getline(std::cin, pub_house);
        std::cout << "Год издания" << std::endl;
        std::getline(std::cin, year);
        std::cout << "Объем" << std::endl;
        std::getline(std::cin, volume);
        std::cout << conclusion_Multi_volume_edition2() <<std::endl;
        std::cout << "Выберите действие" << std::endl;
        std::cout << "1. Сохранить" << std::endl;
        std::cout << "2. НЕ сохранять" << std::endl;
        std::cin>>b;
        switch (b) {
            case 1:
                a.push_back(conclusion_Multi_volume_edition2());
                break;
            case 2:
                break;
        }
    }
};

/**
  * @class Electronic resource
  *
  * @brief Stores information about the Electronic resources
  *
  * @details This class accepts and processes bibliographic records of ELECTRONIC RESOURCE type
  */
class Electronic_resources{
public:

    std::string author{};       //Author
    std::string title{};        //Title
    std::string sor{};          //Responsibility
    std::string res_des{};      //Resource type designation
    std::string place_of_pub{}; //Place of publication
    std::string pub_house{};    //Publishing house
    std::string year{};         //The year of publishing
    std::string mat_des{};      //Material designation and number of physical units.

    /**
      * @brief Formats a string
      *
      * @details Formatting an electronic resource according to hse standards
      *
      * @param[out] string This string is formatted according to GOST(HSE)
      */
    std::string conclusion_elec(){
        std::ostringstream oss;
        oss<<"1. "<<author<<"."<<title<<"/"<<sor<<". -"<<res_des<<". -"<<place_of_pub<<": "<<pub_house<<", "<<year<<". -"<<mat_des<<".";
        std::string result = oss.str();
        return result;
    }

    /**
      * @brief Collects information
      *
      * @details Collects information by asking the user for it and adds a new element to the list vector.This is a function for formmating electronic resource
      *
      * @param[in] vector Accepts a vector in which the formatted string will be embedded later
      */
    void elec_embed(std::vector<std::string>& a) {
        int b{};
        std::cout << "Напишите автора" << std::endl;
        std::getline(std::cin, author);
        std::cout << "Заглавие" << std::endl;
        std::getline(std::cin, title);
        std::cout << "Cведения об ответственности" << std::endl;
        std::getline(std::cin, sor);
        std::cout << "Обозначение вида ресурса" << std::endl;
        std::getline(std::cin, res_des);
        std::cout << "Место издания" << std::endl;
        std::getline(std::cin, place_of_pub);
        std::cout << "Издательство" << std::endl;
        std::getline(std::cin, pub_house);
        std::cout << "Год издания" << std::endl;
        std::getline(std::cin, year);
        std::cout << "Обозначение материала и количество физических единиц" << std::endl;
        std::getline(std::cin, mat_des);
        std::cout << conclusion_elec() <<std::endl;
        std::cout << "Выберите действие" << std::endl;
        std::cout << "1. Сохранить" << std::endl;
        std::cout << "2. НЕ сохранять" << std::endl;
        std::cin>>b;
        switch (b) {
            case 1:
                a.push_back(conclusion_elec());
                break;
            case 2:
                break;
        }
    }
};

/**
  * @class Components of documents
  *
  * @brief Stores information about the Components of documents
  *
  * @details This class accepts and processes bibliographic records of COMPONENTS OF DOCUMENTS type
  */
class Cons_par_doc{
public:
    std::string info_art{};  //Article Details
    std::string info_sour{}; //Information about the source of the article
    std::string info_loc{};  //Information about the location of the article in the document.

    /**
     * @brief Formats a string
     *
     * @details Formatting an Components of documents according to hse standards
     *
     * @param[out] string This string is formatted according to GOST(HSE)
     */
    std::string conclusion_partdoc(){
        std::ostringstream oss;
        oss<<"1. "<<info_art<<" // "<<info_sour<<". -"<<info_loc<<".";
        std::string result = oss.str();
        return result;
    }

    /**
      * @brief Collects information
      *
      * @details Collects information by asking the user for it and adds a new element to the list vector.This is a function for formmating components of documents according
      *
      * @param[in] vector Accepts a vector in which the formatted string will be embedded later
      */
    void partdoc_embed(std::vector<std::string>& a) {
        int b{};
        std::cout << "Напишите Сведения о статье" << std::endl;
        std::getline(std::cin, info_art);
        std::cout << "Сведения об источнике статьи" << std::endl;
        std::getline(std::cin, info_sour);
        std::cout << "Сведение о местоположении статьи в документе." << std::endl;
        std::getline(std::cin, info_loc);
        std::cout << conclusion_partdoc() <<std::endl;
        std::cout << "Выберите действие" << std::endl;
        std::cout << "1. Сохранить" << std::endl;
        std::cout << "2. НЕ сохранять" << std::endl;
        std::cin>>b;
        switch (b) {
            case 1:
                a.push_back(conclusion_partdoc());
                break;
            case 2:
                break;
        }
    }
};

/**
  * @class Unpublished document
  *
  * @brief Stores information about the Unpublished document
  *
  * @details This class accepts and processes bibliographic records of UNPUBLISHED DOCUMENT type
  */
class Unpub_doc{
public:
    std::string author{};       //Author
    std::string title{};        //Title
    std::string nomen_code{};   //cipher of the nomenclature of specialties of scientific workers
    std::string prot_date{};    //protection date
    std::string appr_date{};    //approval date
    std::string sor{};          //Responsibility
    std::string place_of_pub{}; //Place of publication
    std::string year{};         //The year of publishing
    std::string volume{};       //Volume

    /**
     * @brief Formats a string
     *
     * @details Formatting an unpublished document according to hse standards
     *
     * @param[out] string This string is formatted according to GOST(HSE)
     */
    std::string conclusion_unpubdoc(){
        std::ostringstream oss;
        oss<<"1. "<<author<<"."<<title<<":"<<nomen_code<<": "<<prot_date<<": "<<appr_date<<"/"<<sor<<". -"<<place_of_pub<<","<<year<<". - "<<volume<<"." ;
        std::string result = oss.str();
        return result;
    }

    /**
     * @brief Collects information
     *
     * @details Collects information by asking the user for it and adds a new element to the list vector.This is a function for formmating unpublished document according
     *
     * @param[in] vector Accepts a vector in which the formatted string will be embedded later
     */
    void unpub_embed(std::vector<std::string>& a) {
        int b{};
        std::cout << "Напишите автора" << std::endl;
        std::getline(std::cin, author);
        std::cout << "Заглавие" << std::endl;
        std::getline(std::cin, title);
        std::cout << "шифр номенклатуры специальностей научных работников" << std::endl;
        std::getline(std::cin,  nomen_code);
        std::cout << "дата защиты" << std::endl;
        std::getline(std::cin, prot_date);
        std::cout << "дата утверждения" << std::endl;
        std::getline(std::cin, appr_date);
        std::cout << "сведения об ответственности (автор)" << std::endl;
        std::getline(std::cin, sor);
        std::cout << "Место написания" << std::endl;
        std::getline(std::cin, place_of_pub);
        std::cout << "Дата написания" << std::endl;
        std::getline(std::cin, year);
        std::cout << "Объем" << std::endl;
        std::getline(std::cin, volume);
        std::cout << conclusion_unpubdoc() <<std::endl;
        std::cout << "Выберите действие" << std::endl;
        std::cout << "1. Сохранить" << std::endl;
        std::cout << "2. НЕ сохранять" << std::endl;
        std::cin>>b;
        switch (b) {
            case 1:
                a.push_back(conclusion_unpubdoc());
                break;
            case 2:
                break;
        }
    }
};

/**
  * @brief Number and sort
  *
  * @details This function first sorts the resulting vector alphabetically, and then numbers each sorted element
  *
  * @param[in] vector Accepts an unsorted and unnumbered list vector
  */
void sort_numbering(std::vector<std::string>& a) {
    std::sort(a.begin(), a.end());
    for (size_t i = 0; i < a.size(); i++) {
        std::ostringstream oss;
        oss << i + 1 << ". " << a[i];
        std::string c = oss.str();
        a[i] = c;
    }
}

/**
  * @brief Deletion of numbering
  *
  * @details This function removes the numbering of each element of the vector.Vector elements MUST BE numbered
  *
  * @param[in] vector Takes a vector in which each element MUST BE numbered
  */
void removeNumbering(std::vector<std::string>& a) {
    for (std::string& str : a) {
        size_t dotPos = str.find('.');
        if (dotPos != std::string::npos) {
            str = str.substr(dotPos + 2);
        }
    }
}

/**
  * @brief Saves to file
  *
  * @details This function saves each element of the vector to file "txt" line by line
  *
  * @param[in] vector Takes a vector whose elements we want to store
  * @param[in] string Takes the path to the file in which we want to save
  */
void save(std::vector<std::string> a, std::string b){
    std::ofstream file(b);
        for (const auto& item : a) {
            file << item << std::endl;
        }
        file.close();
        std::cout << "Элементы успешно записаны в файл." << std::endl;
}

/**
  * @brief Show list
  *
  * @details This function prints each element of the vector to the screen
  *
  * @param[in] vector Takes a vector whose elements we want to store
  */
void show(std::vector<std::string>& a){
    for(size_t i=0; i<a.size(); i++){
        std::cout<<a[i]<<std::endl;
    }
}

/**
  * @brief Delete element
  *
  * @details This function removes the element specified by the user
  *
  * @param[in] vector Takes a vector from which we want to remove an element
  * @param[in] int Takes the number of the element we want to remove
  */
void delete_elem(std::vector<std::string>& a, int b){
    a.erase(a.begin() + b-1);
}

