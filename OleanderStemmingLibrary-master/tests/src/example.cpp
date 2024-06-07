#include <olestem/stemming/english_stem.h>
#include <olestem/stemming/french_stem.h>
#include <olestem/stemming/german_stem.h>
#include <olestem/stemming/finnish_stem.h>
#include <olestem/stemming/swedish_stem.h>
#include <olestem/stemming/spanish_stem.h>
#include <olestem/stemming/dutch_stem.h>
#include <olestem/stemming/danish_stem.h>
#include <olestem/stemming/italian_stem.h>
#include <olestem/stemming/norwegian_stem.h>
#include <olestem/stemming/portuguese_stem.h>
#include <olestem/stemming/russian_stem.h>

#include <iostream>
#include <string>


int main()
    {
    //the word to be stemmed
    std::wstring word(L"documentation");
    
    stemming::english_stem<> StemEnglish;
    std::wcout << L"(English) Original text:\t" << word.c_str() << std::endl;
    
    StemEnglish(word);
    //now the variable "word" should equal "document"
    std::wcout << L"(English) Stemmed text:\t" << word.c_str() << std::endl;
    //try a similar word that should have the same stem
    word = L"documenting";
    std::wcout << L"(English) Original text:\t" << word.c_str() << std::endl;
    StemEnglish(word);
    //now the variable "word" should equal "document"
    std::wcout << L"(English) Stemmed text:\t" << word.c_str() << std::endl;

    //Now try a French word
    stemming::french_stem<> StemFrench;
    word = L"continuellement";
    std::wcout << L"\n(French) Original text:\t" << word.c_str() << std::endl;
    StemFrench(word);
    //now the variable "word" should equal "continuel"
    std::wcout << L"(French) Stemmed text:\t" << word.c_str() << std::endl;

    //Many other stemmers are also available
    stemming::german_stem<> StemGerman;
    stemming::finnish_stem<> StemFinnish;
    stemming::swedish_stem<> StemSwedish;
    stemming::dutch_stem<> StemDutch;
    stemming::spanish_stem<> StemSpanish;
    stemming::italian_stem<> StemItalian;
    stemming::norwegian_stem<> StemNorwgian;
    stemming::danish_stem<> StemDanish;
    stemming::portuguese_stem<> StemPortuguese;

    /*if you are using std::string (ANSI strings) then convert it to a temporary
    wchar_t buffer, assign that to a std::wstring, and then stem that.*/
    std::string ANSIWord("documentation");
    wchar_t* UnicodeTextBuffer = new wchar_t[ANSIWord.length()+1];
    std::wmemset(UnicodeTextBuffer, 0, ANSIWord.length()+1);
    std::mbstowcs(UnicodeTextBuffer, ANSIWord.c_str(), ANSIWord.length());
    word = UnicodeTextBuffer;
    StemEnglish(word);
    //now the variable "word" should equal "document"
    std::wcout << L"\nDemonstrating the stemming of an ANSI string:\n";
    std::wcout << L"(English) Original text:\t" << ANSIWord.c_str() << std::endl;
    std::wcout << L"(English) Stemmed text:\t" << word.c_str() << std::endl;

    return 0;
    }
