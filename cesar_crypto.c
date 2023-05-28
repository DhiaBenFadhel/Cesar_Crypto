#include <stdio.h>
#include <string.h>
#include <ctype.h> // To use the isupper function

char encrypt(char* text,int shift, char* encrypted_text){
    int l = strlen(text); // length of input text
    int ascii_val;
    for (int i = 0; text[i] != '\0'; i++) // looping through characters of text
    {
        if (isupper(text[i])) // check for Uppercase characters
        {
            ascii_val = (int)'A'; // setting the base ASCII value
        }
        else
        {
            ascii_val = (int)'a'; // setting the base ASCII value
        }
        char moved_char = (char)((((int)text[i]) - ascii_val + shift) % 26 + ascii_val); // Returning the new character after shifting
        encrypted_text[i] = moved_char; // adding the new character to encrypted_text
    }
    encrypted_text[l - 1] = '\0'; // adding a null character in the end of encrypted_tex to remove the random symbole that gets added
}

void decrypt(char* text,int shift, char* decrypted_text){
    int l = strlen(text); // length of input text
    int ascii_val;
    for (int i = 0; text[i] != '\0'; i++)// looping through characters of text
    {
        if (isupper(text[i])) // check for Uppercase characters
        {
            ascii_val = (int)'A';// setting the base ASCII value
        }
        else
        {
            ascii_val = (int)'a';// setting the base ASCII value
        }
        char moved_char = (char)((((int)text[i]) - ascii_val - shift) % 26 + ascii_val); // Returning the old character beforr shifting
        decrypted_text[i] = moved_char;// adding the old character to decrypted_text
    }
    decrypted_text[l - 1] = '\0';// adding a null character in the end of decrypted_tex to remove the random symbole that gets added
}

#define max_length 100 

int main()
{
    char text[max_length],encrypted_text[max_length],decrypted_text[max_length];
    int shift,choice;
    printf("Enter Your phrase: ");
    fgets(text,max_length,stdin);
    printf("\n");
    printf("Do You want to Encrypt(1) or decrypt(2) This phrase '%s' ? \n",text);
    printf("Enter your choice:");
    scanf("%d", &choice);
    printf("What is the Shift to use? : ");
    scanf("%d", &shift);
    // creating the choice menu
    switch (choice)
    {
    case 1:
        encrypt(text, shift, encrypted_text);
        printf("Encrypted phrase: %s",encrypted_text);
        break;
    case 2:
        decrypt(text, shift, decrypted_text);
        printf("Decrypted phrase: %s",decrypted_text);
        break;
    default:
        break;
    }
    return 0;
}

