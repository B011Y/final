#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "main.cpp"


TEST_SUITE("Function Tests") {
    TEST_CASE("sort_numbering") {
        std::vector<std::string> input = {"b", "c", "a"};
        std::vector<std::string> expected = {"1. a", "2. b", "3. c"};
        sort_numbering(input);
        CHECK(input == expected);
    }

    TEST_CASE("removeNumbering") {
        std::vector<std::string> input = {"1. a", "2. b", "3. c"};
        std::vector<std::string> expected = {"a", "b", "c"};
        removeNumbering(input);
        CHECK(input == expected);
    }

    TEST_CASE("save") {
        std::vector<std::string> input = {"a", "b", "c"};
        std::string filename = "output.txt";
        save(input, filename);

        std::ifstream file(filename);
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string fileContents = buffer.str();

        CHECK(fileContents == "a\nb\nc\n");
    }
    TEST_CASE("show function displays elements of vector"){
        std::vector<std::string> vec {"apple", "banana", "orange"};
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
        show(vec);
        std::string output = buffer.str();
        std::string expectedOutput = "apple\nbanana\norange\n";
        CHECK(output == expectedOutput);
        std::cout.rdbuf(oldCout);
    }

    TEST_CASE("delete_elem function removes element at specified index"){
        std::vector<std::string> vec {"apple", "banana", "orange"};
        delete_elem(vec, 2);
        CHECK(vec.size() == 2);
        CHECK(vec[0] == "apple");
        CHECK(vec[1] == "orange");
    }
    TEST_CASE("conclusion_One_volume_edition1 returns the correct string format") {
        Book book{};
        book.author = "Kim Maxim";
        book.title = "Book Title";
        book.sor = "Source";
        book.pub_state = "Publication State";
        book.place_of_pub = "Place of Publication";
        book.pub_house = "Publisher";
        book.year = "2023";
        book.volume = "1";

        std::string expectedOutput = "1. Kim Maxim.Book Title/Source. -Publication State. -Place of Publication: Publisher, 2023. -1.";
        CHECK(book.conclusion_One_volume_edition1() == expectedOutput);
    }

    TEST_CASE("conclusion_One_volume_edition2 returns the correct string format") {
        Book book{};
        book.title = "Book Title";
        book.sor = "Source";
        book.pub_state = "Publication State";
        book.place_of_pub = "Place of Publication";
        book.pub_house = "Publisher";
        book. year = "2023";
        book.volume = "1";

        std::string expectedOutput = "1. Book Title/Source. -Publication State. -Place of Publication: Publisher, 2023. -1.";
        CHECK(book.conclusion_One_volume_edition2() == expectedOutput);
    }

    TEST_CASE("conclusion_Multi_volume_edition1 returns the correct string format") {
        Book book{};
        book.author = "Kim Maxim";
        book.title = "Book Title";
        book.sor = "Source";
        book.place_of_pub = "Place of Publication";
        book.pub_house = "Publisher";
        book.year = "2023";
        book. num_of_vol = "2";
        book.series = "Book Series";

        std::string expectedOutput = "1. Kim Maxim.Book Title/Source. -Place of Publication: Publisher, 2023. -2. -Book Series.";
        CHECK(book.conclusion_Multi_volume_edition1() == expectedOutput);
    }

    TEST_CASE("conclusion_Multi_volume_edition2 returns the correct string format") {
        Book book{};
        book.author = "Kim Maxim";
        book.title = "Book Title";
        book.des_and_num = "Description and Number";
        book.sor = "Source";
        book.place_of_pub = "Place of Publication";
        book.pub_house = "Publisher";
        book. year = "2023";
        book.volume = "1";
        book.series = "Book Series";

        std::string expectedOutput = "1. Kim Maxim.Book Title.Description and Number/Source. -Place of Publication: Publisher, 2023-1. -Book Series.";
        CHECK(book.conclusion_Multi_volume_edition2() == expectedOutput);
    }

    TEST_CASE("conclusion_elec returns the correct string format") {
        Electronic_resources elec{};
        elec.author = "Kim Maxim";
        elec.title = "Book Title";
        elec.sor = "Source";
        elec.res_des = "Resource Description";
        elec.place_of_pub = "Place of Publication";
        elec.pub_house = "Publisher";
        elec.year = "2023";
        elec.mat_des = "Material Description";

        std::string expectedOutput = "1. Kim Maxim.Book Title/Source. -Resource Description. -Place of Publication: Publisher, 2023. -Material Description.";
        CHECK(elec.conclusion_elec() == expectedOutput);
    }

    TEST_CASE("conclusion_partdoc returns the correct string format") {
        Cons_par_doc par{};
        par.info_art = "Article Title";
        par.info_sour = "Source";
        par.info_loc = "Location";

        std::string expectedOutput = "1. Article Title // Source. -Location.";
        CHECK(par.conclusion_partdoc() == expectedOutput);
    }
    TEST_CASE("conclusion_unpubdoc returns the correct string format") {
        Unpub_doc unpub{};
        unpub.author = "Kim Maxim";
        unpub.title = "Document Title";
        unpub.nomen_code = "Nomenclature Code";
        unpub.prot_date = "2023-06-15";
        unpub.appr_date = "2023-06-16";
        unpub.sor = "Source";
        unpub.place_of_pub = "Place of Publication";
        unpub.year = "2023";
        unpub.volume = "1";

        std::string expectedOutput = "1. Kim Maxim.Document Title:Nomenclature Code: 2023-06-15: 2023-06-16/Source. -Place of Publication,2023. - 1.";
        CHECK(unpub.conclusion_unpubdoc() == expectedOutput);
    }
}
