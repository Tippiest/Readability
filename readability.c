#include <stdio.h>
#include <cs50.h>
#include <string.h>

int Coleman(float L, float S);
float AverageLetter(string text);
float AvgSentence(string text);


int main(void)
{

    float letters;
    float sentences;
    string text;
    int grade;

    //Collect text you want to grade
    text = get_string("Enter a text:");

    //Get the average of the letters and sentences
    letters = AverageLetter(text);
    sentences = AvgSentence(text);

    //grade the text based off the averages
    grade = Coleman(letters, sentences);

    if(grade >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }

    if(grade < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }

    else{
        printf("Grade %i\n", grade);

    }




}


//function that calculates the grade level using average letters and sentences per 100 words
//Inp: 2 floats, L representing the avg num of letters and S representing the avg num of sentences
//Out: Integar representing the grade
int Coleman(float L, float S)
{
    float index;
    int grade;

    //The Coleman-Liau index
    index = 0.0588 * L - 0.296 * S - 15.8;

    //Turn the float into an int
    //Adjust the index in case it's too low
    if( ((int)index + 1) - index <= 0.5)
    {
        index++;
    }

    grade = (int)(index);


    return grade;
}

//Inp: the text as a string
//Out: Float as the average
float AverageLetter(string text)
{
    float words = 0.0;
    float average;
    float count = 0;

    //go through ever character of the string
    for(int i = 0; i < strlen(text); i++ )
    {
        //if its the first character and it isnt blank count as word
        if(i == 0 && text[i] != '\0' )
        {
            words++;
        }
        //if there isnt a space and its a letter in the alphabet then count it as a letter
        if( text[i] != ' ' && (text[i] >= 65 && text[i] <= 122) )
        {
            count++;

        }
        //if there is a space count the previous letters as a word
        if(text[i] == ' ')
        {
            words++;
        }

    }


    //take the average
    average = (count / words) * 100.0;

    return average;
}

//Inp: text as a string
//Out: average sentence portrayed as a float
float AvgSentence(string text)
{
    //inititalize variables
    float sentence = 0.0;
    float words = 0.0;
    float average;

    //a loop that goes through ever character of the string
    for(int i=0;i<strlen(text);i++)
    {
        //if its the first letter and it contains a character then count it as a word
        if(i == 0 && text[i] != '\0' )
        {
            words++;
        }

        //if it is a sentence ender, count as a sentence
        if(text[i] == 46 || text[i] == 63 || text[i] == 33)
        {
            sentence++;
        }
        //if there is a space count the previous letters as a word
        if(text[i] == ' ')
        {
            words++;
        }


    }



    //sentences per 100 words
    average = sentence / words * 100.0;

    return average;

}