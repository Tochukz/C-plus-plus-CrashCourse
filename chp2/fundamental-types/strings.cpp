#include <cstdio>

int main() {
    // c-type strings 
    char english[] = "The book hold a house of gold.";
    char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b"; 

    // automatic string concatination 
    char message[] = "I am "  
                   " an " "everything "
                   "kind of" " developer."; 

    printf("English: %s \n", english); // English: The book hold a house of gold. 
    printf("Chinese: %s \n", chinese); // Chinese: fN-NΩü g─₧╤æK
    printf("%s \n", message); // I am  an everything kind of developer.
}