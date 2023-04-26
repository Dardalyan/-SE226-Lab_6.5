# TASK 1
def commonList(list1:list,list2:list):
    list3 =[]
    for i in list1:
        if i in list2:
            list3.append(i)
    return list3

intlist1 = [1,2,3,5,6]
intlist2 = [2,5,6,8,9,0]
print(commonList(intlist1,intlist2))


# TASK 2
strList = ["tenet","palindrome","apple","racecar","civic","banana","crossbow"]
def getPalindromeList(strList:list):
    returnedList = []
    for i in strList:
        if i == i[::-1]:
            returnedList.append(i)
    return returnedList

print(getPalindromeList(strList))

my_list = []
for i in range(132):
    my_list.append(i)


# TASK 3
def prime_eratosthenes(a_list:list):
     last_index = a_list[-1]
     p=2
     temp=[]
     while(p<last_index):
         for i in range(2, last_index):
             temp.append(i * p)
         p+=1

     for i in temp:
         if i in a_list:
             a_list.remove(i)
     return a_list

print(prime_eratosthenes(my_list))


# TASK 4
def anagrams(word, word_list):
    outputlist=[]
    charsOfWord = list(word)
    charsOfWord.sort()
    for i in word_list:
        i = i.lower()
        charsOfCurrentWord= list(i)
        charsOfCurrentWord.sort()
        if charsOfCurrentWord == charsOfWord:
            outputlist.append(i)
    return outputlist



my_list2 = ["enlists", "google", "inlets", "banana"]
print(anagrams("listen",my_list2))






