/* 
 * File:   main.c
 * Author: Miguel
 *
 * Created on April 9, 2014, 8:42 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * This function takes english_word and returns a pointer to an array of characters that contains a pig latin word it has translated (can also be interpreted as a string).
 */
char *english2piglatin(char *english_word) 

{
    
    char *piglatin_word; //the array for the pig latin translation
    piglatin_word = malloc(strlen(english_word)+3); /* extra characters for the ay and the NULL character */
    
    char vowels[] = "aeiouAEIOU;"; //sets the target characters I am looking for.
    piglatin_word = strpbrk(english_word, vowels); //strpbrk returns a pointer to the first instance of the characters I have defined in the second argument, which is useful for moving characters around.
    
    strncat(piglatin_word, english_word, strcspn(english_word, vowels)); //I am taking advantage of the limiting function of strncat to only copy the number of elements strcspn returns, and then concatenate those characters behind the word I am forming
    strcat(piglatin_word, "ay"); //final step of pig latin translation
    
    return piglatin_word; //returns the translated word
    free(piglatin_word); //just for safe practice, and for looping again.
}
int main(int argc, char** argv) {
    puts("English to Pig Latin Translator! Try it out: ");
    char english_string[5000]; //5000 characters is the max character input for a string here.
    scanf("%[^\n]", english_string); //scans until the scanner encounters a new line character
    
    int i = 0;
    int c = 0;
    
    char *piglatin[5000]; //defines the pig latin array of strings, the final array to print the whole translation
    char *temp; //temp array used to do the old flip flop on arrays inside of the while loop coming up
    
    
    temp = strtok(english_string, " ,.?!"); //begins the tokenizing of the string!
    
    
    /*
     * Here, this while loop takes care of tokenizing and storing each token in the word
     */
    
    
    while(temp != NULL)
    {
       
        piglatin[i] = malloc(strlen(temp)+3); //allocates just enough memory to fit each token + the new characters tacked on to the string
        strcpy(piglatin[i], temp); //copies the temp string into the array of strings
        temp = strtok(NULL, " ,.?!"); //continues scanning the english_string!
        i++;
    }
    /*
     * The for loop here is used to translate and print each element of the array of strings I have created.
     */
    for(c = 0; c < i; c++)
    {
        strcpy(piglatin[c], english2piglatin(piglatin[c])); //this translates each word in the array of strings, and overwrites the old element in the array (it has enough space, refer to the while loop before)
        printf("%s ", piglatin[c]); //I couldn't use puts here because puts automatically puts a new line after each entry. Therefore, printf was the logical choice.
    }
   
    return 0; //success!
   }






