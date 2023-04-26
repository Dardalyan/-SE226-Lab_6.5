#include <iostream>
#include <list>
using namespace std;

// Task 1
list<int> commonList(list<int> list1, list<int> list2)
{   
    list<int>list3;
    for (int i : list1) {
        for (int j : list2) {
            if (i == j)
                list3.push_front(i);
        }
    }
    return list3;
}

// Task 2
list<string> getPalindromeList(list<string> paramlist)
{
    list<string> returnedList;
    for (string i : paramlist)
    {
        string reverse = "";
        for (int j = i.length()-1;j >= 0 ; j--) {
            reverse += i[j];
        }
        if (reverse == i)
        {
            returnedList.push_front(i);
        }
    }

    return returnedList;
}


// Task 3
list<int> prime_eratosthenes(list<int> paramlist)
{
    int p = 2;
    list<int>temp;
    int lastIndex = paramlist.back();
 
    while (p < lastIndex)
    {
        for (int i = 2; i < lastIndex; i++)
        {
            temp.push_back(i * p);
        }
        p += 1;
    }

    list<int>::iterator iter = temp.begin();
    int* tempArray = new int[temp.size()];
    int i= 0;
    while (i <= temp.size() - 1) {
        tempArray[i] = *iter;
        advance(iter, 1);
        i++;
    }

    i = 0;
    iter = paramlist.begin();
    int* myArray = new int[paramlist.size()];
    while (i <= paramlist.size() - 1) {
        myArray[i] = *iter;
        advance(iter, 1);
        i++;
    }

    list<int>returnedList;
    iter = paramlist.begin();
    i = 0;
    int size = paramlist.size();
    while (true)
    {
        for (int j = 0; j < temp.size(); j++) {
            if (tempArray[j] == *iter) {
                for (int i = 0; i < paramlist.size(); i++)
                    if (myArray[i] == *iter)
                        myArray[i] = NULL;
            }
        }
        advance(iter, 1);
        i++;
        if (i == size)
            break;

    }

    for (int i = 0; i < paramlist.size(); i++)
    {
        if (myArray[i] != 0)
            returnedList.push_back(myArray[i]);
    }

    return returnedList;
}

// Task 4
list<char> sort(list<char> unsorted);

list<string> anagrams(string word,list<string> wordList)
{
    list<string>outputlist;
    list<char>charsWord;
    for (int i = 0; i < word.length(); i++)
        charsWord.push_back(word[i]);

    charsWord = sort(charsWord);
    /* 
    * SORTED LIST CHECKÝNG AND IT LOOKD FINE
   
    list<char>::iterator it = charsWord.begin();
    for (int i = 0; i <= charsWord.size(); i++) {
        cout << *it<<"-";
        advance(it, 1);
    }*/

    list<list<char>>seperateds;

    list<string>::iterator iter_s = wordList.begin();
    
    // AFTER THIS LOOP: there is a problem that has been tried  so much but I couldn't solve that !
    for (int i = 0; i <= wordList.size(); i++) {

        list<char>letters;

        for (int j = 0; j < iter_s->length(); j++) {
            string aWord = *iter_s;
            letters.push_back(aWord[j]);
        }

        letters = sort(letters);
        seperateds.push_back(letters);
        advance(iter_s, 1);

    }
    
    
    string* myArray = new string[wordList.size()];
    iter_s = wordList.begin();
    for (int i = 0; i <= wordList.size(); i++) {
        myArray[i] = *iter_s;
        advance(iter_s, 1);
    }

    
    list<list<char>>::iterator cs_iter = seperateds.begin();
    
    for (int i = 0; i < seperateds.size(); i++) {
        if (charsWord == *cs_iter)
            outputlist.push_back(myArray[i]);
        advance(cs_iter, 1);
    }
    
       
    return  outputlist;
}



// my helper function
void printList(list<int> list)
{
    for (int i : list)
    {
        cout << i << endl;

    }
}

// my helper function
void printList(list<string>  list)
{
    for (string i : list)
    {
        cout << i << endl;

    }
}

// my helper function Note: it works fine !
list<char> sort(list<char> unsorted)
{
    list<char> sortedList;
    int i = 0;
    int size = unsorted.size();
    while (true)
    {
        char lowestChar = 'z';
        list<char>::iterator iter = unsorted.begin();
        
        for (int j = 0; j < unsorted.size(); j++) {
            if (*iter < lowestChar)
                lowestChar = *iter;
            advance(iter, 1);
        }
        unsorted.remove(lowestChar);
        sortedList.push_back(lowestChar);
        i++;
        if (i == size)
            break;
    }
    
    return sortedList;

}

int main()
{
    //Task1
    list<int>list1 = { 1, 2, 3, 5, 6 };
    list<int>list2 = { 6, 8, 2, 0, 9 };
    list<int>list3 = commonList(list1, list2);
    cout << "\nTask1 Common List: " << endl;
    printList(list3);

    string isim = "burak";
    
    //Task 2
    string strList[] = {"tenet", "palindrome", "apple", "racecar", "civic", "banana", "crossbow"};

    list<string>mixesList;
    for (int i = 0; i < strList->length(); i++) {
        mixesList.push_back(strList[i]);
    }

    list<string>palindromeList=getPalindromeList(mixesList);
    cout << "\nTask2 Palindrome List: " << endl;
    printList(palindromeList);

   

    //Task 3
    list<int>my_list;
    for (int i = 1; i < 133; i++)
        my_list.push_back(i);

    list<int>primeList =  prime_eratosthenes(my_list);

    list<int>::iterator iter = primeList.begin();
    int i = 0;
    cout << "\nTask 3 Primelist: " << endl;
    while (i <= primeList.size() - 1) {
        cout << *iter << "-";
        advance(iter, 1);
        i++;
    }

    //Task 4
    cout << "\n" << endl;
    string word = "listen";
    list<string>wordList;
    wordList.push_back("enlists");
    wordList.push_back("google");
    wordList.push_back("inlets");
    wordList.push_back("banana");

    list<string>anagram = anagrams(word, wordList);
    
    list<string>::iterator lastIter = anagram.begin();
    
    for (int i = 0; i <= anagram.size(); i++) {
        cout << *lastIter << endl;
        advance(lastIter, 1);
    }

    
    return 0;
}


