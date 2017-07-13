#include <iostream>     //cout
#include <regex>

#include "boost/filesystem.hpp"
#include "boost/range/adaptor/reversed.hpp"


//#include <vector>       //vector
//#include <memory>       //shared ptr
//#include "src/pepper/html/hr.hpp"
//#include "src/pepper/html/img.hpp"
//#include "src/pepper/attributes/attribute.h"

//using namespace SC::pepper::html;
//using std::cout;
//using std::endl;
//using namespace std;
//
//using namespace SC::pepper::attribute;

namespace fs = boost::filesystem;

using std::cout;
using std::cin;
using std::cerr;
using std::endl;


#include "fcgi/fcgio.h"


//broken
//std::vector<std::string> && filter(std::vector<std::string>::iterator begin,
//                                   std::vector<std::string>::iterator end,
//                                   std::function<bool(std::string)> function) {
//    std::vector<std::string> holder;
//    for (;begin!=end;++begin) {
//        if (function(*begin)) holder.insert(holder.end(),*begin);
//    }
//    return std::move(holder);
//}


int main ()
{
//
//    vector<shared_ptr<component>> vec;
//    vector<shared_ptr<attribute>> attributes;
//
//
//    vec.push_back (shared_ptr<component>(new hr()));
//    vec.push_back (shared_ptr<component>(new img()));
//
//    attributes.push_back (shared_ptr<attribute>(new attribute ("src","/a/b/c")));
//    attributes.push_back (shared_ptr<attribute>(new attribute ("width","320")));
//    attributes.push_back (shared_ptr<attribute>(new attribute ("height","320")));
//    attributes.push_back (shared_ptr<attribute>(new attribute ("test","320")));
//
//
//    for (const shared_ptr<attribute> & i : attributes)
//        vec[1]->attribute_insert (*i);
//
//    for (const shared_ptr<component> & it : vec)
//        cout << it->edit () << endl;

    std::locale old;
    std::locale::global(std::locale("fr_FR.UTF-8"));

    fs::path path_js(u8"js/");
    fs::path path_css(u8"css/");
    fs::path path_vendor(u8"vendor/");

    // Backup the stdio streambufs
    std::streambuf * cin_streambuf  = std::cin.rdbuf();
    std::streambuf * cout_streambuf = std::cout.rdbuf();
    std::streambuf * cerr_streambuf = std::cerr.rdbuf();

    FCGX_Request request;

    FCGX_Init();
    FCGX_InitRequest(&request, 0, 0);

    while (FCGX_Accept_r(&request) == 0) {
        fcgi_streambuf cin_fcgi_streambuf(request.in);
        fcgi_streambuf cout_fcgi_streambuf(request.out);
        fcgi_streambuf cerr_fcgi_streambuf(request.err);

        std::cin.rdbuf(&cin_fcgi_streambuf);
        std::cout.rdbuf(&cout_fcgi_streambuf);
        std::cerr.rdbuf(&cerr_fcgi_streambuf);



        std::cout << u8"Content-type: text/html" << endl << endl
                  << u8"<!DOCTYPE html>" << endl
                  << u8"<html>" << endl
                  << u8"<head>" << endl
                  << u8"<meta charset=\"UTF-16\">" << endl
                  << u8"<title>Hello, World!</title>" << endl;



        std::vector<std::string> include_all, include_js, include_css;
        for (fs::recursive_directory_iterator it(path_vendor,fs::symlink_option::recurse);it!=fs::recursive_directory_iterator{};++it) {
            if (fs::is_regular_file(it->path())) include_all.push_back(it->path().string());
        }

        include_css.reserve(10);
        include_js.reserve(10);

        std::regex regex_js(u8".+\\.min\\.js");
        std::regex regex_css(u8".+\\.min\\.css");

        for (auto i : include_all) {
            if (std::regex_match(i,regex_js))
            {
                include_js.push_back(i);
            }
            if (std::regex_match(i,regex_css))
            {
                include_css.push_back(i);
            }
        }

        for (const auto &js:boost::adaptors::reverse(include_js))
            cout << u8"\t<script type=\"text/javascript\"src=\"" << js << u8"\"></script>"<<endl;

        for (auto css:include_css)
            cout << u8"\t<link rel=\"stylesheet\" type=\"text/css\" href=\""<<css<< u8"\">"<<endl;

        std::cout
                << u8"    <title>Hello, World!</title>\n"
                << u8"  </head>\n"
                << u8"  <body>\n"
                << u8"  <div class=\"container\">\n"
                << u8"    <h1>Hello, World! folk</h1>\n";

        std::cout
                << u8"  </div>"
                << u8"  </body>\n"
                << u8"</html>\n";

        // Note: the fcgi_streambuf destructor will auto flush
    }

    // restore stdio streambufs
    std::cin.rdbuf(cin_streambuf);
    std::cout.rdbuf(cout_streambuf);
    std::cerr.rdbuf(cerr_streambuf);

    std::locale::global(old);
    return 0;
}