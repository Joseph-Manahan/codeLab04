
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

/* function returns a vector of dictionary words - possible inputs are 1, 2, & 3 *
 * representing three different word lists. Function will return word list #3 if *
 * any integer besides 1 or 2 is passed in.                                      *
 */
vector<string> fillVector(int choice);



 /* function returns a vector of dictionary words - possible inputs are 1, 2, & 3 *
 * representing three different word lists. Function will return word list #3 if *
 * any integer besides 1 or 2 is passed in.                                      *
 */
 /* Note: not all versions of C++ support direct definition of a vector, hence a *
  * temporary array is used here.                                                *
  */
vector<string> fillVector(int choice) {
     vector<string> dict;
     
    string temp1[] ={"airy", "aisle", "aisles", "ajar", "akimbo", "akin", "juveniles",
                     "juxtapose", "knowledges", "known", "president", "tries", "trifle",
                     "tugs", "wrongdoers", "wroth", "wyvern", "xenophon", "xylol", "yodle",
                     "yurt", "zeugma", "ziggurat", "zootomy"};
     unsigned int size1 = 24;
    string temp2[] = {"aback", "abased", "acknowledgers", "administers", "affair",
                     "aforementioned", "aggrieving", "agitating", "agree", "airlines", "ajar",
                     "basin", "bawdy", "cheap", "cheated", "examiner", "excel",
                     "lewdness", "liberal", "mathematician", "ordered", "president", "sandwich",
                     "swagger", "swarm", "vomit", "yell", "zero", "zodiac", "zoo"};
     unsigned int size2 = 30;
    string temp3[] = {"ajar", "anachronism", "bleed", "bystander", "chariot", "clay",
                     "contrive", "critiques", "databases", "derivative", "dog", "earthenware",
                     "basin", "bawdy", "cheap", "cheated", "examiner", "excel",
                     "echo", "fatiguing", "floppy", "goldsmith", "halt", "implies",
                     "jam", "klutz", "lively", "malt", "meteor", "nonsense", "orphans",
                     "paint", "playful", "railroad", "revolt", "shark", "spook", "syntax",
                     "tablet", "thing", "ugly", "vigilant", "whirr", "yell", "zap", "zoo"};
     unsigned int size3 = 46;
     switch (choice) {
         case 1:
                 for (unsigned int i = 0; i < size1; i++) {
                    dict.push_back(temp1[i]);
                }
                break;
         case 2:
                 for (unsigned int i = 0; i < size2; i++) {
                    dict.push_back(temp2[i]);
                }
                break;
         default:
                 for (unsigned int i = 0; i < size3; i++) {
                    dict.push_back(temp3[i]);
                }
     }//end switch
     
     
     return dict;
 } //end fillVector()
 
 int seqSearch(const vector<string>& words, const string& word) {
    for (size_t i=0; i < words.size(); i++) {
       if (words.at(i) == word) {
          return i;
       }
    }
    return -1;
 }
 
 void insertWord(vector<string>& words, const string& newWord) {
    size_t i;
    for (i = 0; i < words.size(); i++) {
        if (words.at(i) > newWord) {
            break;
        }
    }
    words.insert(words.begin()+i, newWord);
}

void deleteWord(vector<string>&words, const string& delWord) {
    int delIndex = seqSearch(words, delWord);
    if (delIndex == -1) {
        cout << "Your word was '" << delWord << "'. We did not find your word." << endl;
    } else {
        words.erase(words.begin() + delIndex);
        cout << "Your word was '" << delWord << "'. The word '" << delWord << "' has been deleted." << endl;
        if (delIndex == 0) {
            cout << " The next word would be '" << words.at(delIndex) << "' \n There is no word before '"<< delWord << "'" << endl;
        } else if (delIndex == words.size()) {
            cout  << " There is no word following '"<< delWord << "'" << "\n The previous word would be '" << words.at(words.size()-1) << "'" << endl;
        } else {
            cout << " The next word would be '" << words.at(delIndex) << "'\n The previous word would be '" << words.at(delIndex-1) << "'" << endl;
        }
    }
}
 
int main() {
    int num;
    string searchWord;
    cout << "Which Dictionary should be opened? Enter \"1\", \"2\", or \"3\":"<< endl;
    cin >> num;
    if (num < 1 || num > 4) {
       return 1;
    }
    vector<string> words = fillVector(num);
   cout << "Enter a word to search for in the chosen Dictionary:" << endl;
   cin >> searchWord;
   int search = seqSearch(words, searchWord);
   if (search == -1) {
      cout << "Your word was '"<<searchWord<<"'. We did not find your word. Adding word to dictionary..." << endl;
      insertWord(words, searchWord);
      cout << "Inserted!" << endl;
      int newSearch = seqSearch(words, searchWord);
       if (newSearch == 0) {
          cout <<" The next word would be '"<< words.at(newSearch+1)<<
          "'.\n There is no word before '"<<searchWord<<"'."<<endl;
       } else if (newSearch == words.size()-1) {
          cout <<" There is no word following '"<<searchWord<<
          "'.\n The previous word would be '"<<words.at(newSearch-1)<<"'." << endl;
       } else {
           cout << " The next word would be '"<<words.at(newSearch+1)<<"'." << endl <<
                 " The previous word would be'"<<words.at(newSearch-1)<<"'." << endl;
       }
   } else {
      if (search == 0) {
         cout << "Your word was '"<<searchWord<<"'. The next word would be '"<< words.at(search+1)<<
         "'.\n There is no word before '"<<searchWord<<"'."<<endl;
      } else if (search == words.size()-1) {
         cout << "Your word was '"<<searchWord<<"'. There is no word following '"<<searchWord<<
         "'.\n The previous word would be '"<<words.at(search-1)<<"'." << endl;
      } else {
         cout <<"Your word was '"<<searchWord<<"'. The next word would be '"<<words.at(search+1)<<
         "'. The previous word would be '"<<words.at(search-1)<<"'."<< endl;
      }
   }
    string delWord;
    cout << "Enter a word to delete from the chosen Dictionary:" << endl;
    cin >> delWord;
    deleteWord(words, delWord);
    
    for (const string& word : words) {
         cout << word << endl;
      }
    return 0;
}
