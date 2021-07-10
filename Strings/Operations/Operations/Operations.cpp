#include<iostream>
#include<cstdio>

using namespace std;

class Array
{

private:

    char* A;
    
    
public:

     Array();                      // Default Unparametreized Constructor

     ~Array()                      // Destructor
     {
        delete[]A;
     }

     void display();
     int length();
     void upper_to_lower();
     void lower_to_upper();
     void toggle();
     void v_and_c();
     void words();
     void valid();
     void reverse1();
     void reverse2();
     void compare();
     void palindrome();
     void duplicates1();
     void duplicates2();
     void duplicates3();
     void anagram();
     void permutation1(int k);

};

// Constructor

Array::Array()
{

    A = new char[50];                                             // Dynamic memory is allocated to our character Pinter
    cout << "\nPlease Enter Your String : ";
    cin.getline(A, 49);                                           // Spaces are Allowed    (1 is less than actual size for Null Character '\0')

    //cin >> A;                                                   // No Space Allowded
}


int main()
{
    Array A1;
    A1.display();
    int choice;
    do
    {
        cout << "\nPlease Enter Your Choice :" << endl;
        cout << "\n1] Calculate the Length of String" << endl;
        cout << "2] Convert From Lowercase to Uppercase" << endl;
        cout << "3] Convert From Uppercase to Loweracse" << endl;
        cout << "4] Toggle the String" << endl;
        cout << "5] Calulate Vowels and Consonants" << endl;
        cout << "6] Calulate Number of Words" << endl;
        cout << "7] Check Validation of String" << endl;
        cout << "8] Reverse a String (Reverse Copying)" << endl;
        cout << "9] Reverse a String (Using same String)" << endl;
        cout << "10] Compairing Strings" << endl;
        cout << "11] Checking Palindrome" << endl;
        cout << "12] Finding Duplicates Without Hashing" << endl;
        cout << "13] Finding Duplicates With Hashing" << endl;
        cout << "14] Finding Duplicates Using Bitwise Operation" << endl;
        cout << "15] Checking Anagram" << endl;
        cout << "16] Finding all Possible Permutations" << endl;
        cout << "\nFor Exiting Enter : -1" << endl;
        cout << "\nChoice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "\nThe Length of given String is : " << A1.length() << endl;
            break;


        case 2:

            A1.lower_to_upper();
            break;

        case 3:

            A1.upper_to_lower();
            break;

        case 4:

            A1.toggle();
            break;

        case 5:

            A1.v_and_c();
            break;

        case 6:

            A1.words();
            break;

        case 7:

            A1.valid();
            break;

        case 8:

            A1.reverse1();
            break;

        case 9:

            A1.reverse2();
            break;

        case 10:

            A1.compare();
            break;

        case 11:

            A1.palindrome();
            break;

        case 12:

            A1.duplicates1();
            break;

        case 13:

            A1.duplicates2();
            break;

        case 14:

            A1.duplicates3();
            break;

        case 15:

            A1.anagram();
            break;

        case 16:

            int x = 0;

            A1.permutation1(x);
            break;

        }


    } while (choice > 0);



    
}



// Calculating Length

int Array::length()              // Starts counting from 0 but at the same time it counts Null Character '\0', Hence it gets Equalize.
{
    int i;
    for( i = 0; A[i] != '\0' ;i++)
    { 
    }
    return i;
}

// Upper to Lower

void Array::upper_to_lower()
{
   
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] >= 65 && A[i] <= 90)                 // Operation is performed only on those which initially exits in Uppercase
        {
            A[i] = A[i] + 32;
        }
    }

    cout << "\nModified Array : " << A << endl;

}

// Lower to Upper

void Array::lower_to_upper()
{

    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] >= 97 && A[i] <= 122)            // Operation is performed only on those which initially exits in Lowercase
        {
            A[i] = A[i] - 32;
        }
    }

    cout << "\nModified Array : " << A << endl;
}

// Toggle

void Array::toggle()                                      // Here Any Character Other than upper and lower alphabet will remain unchanged
{

    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] >= 65 && A[i] <= 90)
            A[i] += 32;

        else if (A[i] >= 97 && A[i] <= 122)
            A[i] -= 32;
    }

    cout << "\nModified Array : " << A << endl;
}

// Calculating Number of Vowels and Consonant

void Array::v_and_c()             // Here we can use actual vowel in single quote or we can there ASCII Code
{
    int v = 0;
    int c = 0;

    for (int i = 0; A[i] != '\0'; i++)
    {
        
        if (A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U' || A[i] == 97 || A[i] == 101 || A[i] == 105 || A[i] == 111 || A[i] == 117)
            v++;

        else if (A[i] >= 65 || A[i] <= 90 || A[i] >= 97 || A[i] <= 122 )   // If they are not Vowel then they must be consonants but they must be in the range of Alphabets
            c++;
    }

    cout << "\nVowels     : " << v << endl;
    cout << "Consonants : " << c << endl;

}

// Calculate Number of Words

void Array::words()
{
    int w = 0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == 32 && A[i-1] != 32)                                // We have to take care that consicutive spaces should not be counted.
            w++;                                                       // ASCII code of "Space" is 32
    }
    cout << "\nNumber of Words : " << w+1 << endl;
}


// Check Validation            (should only contain Alphabets and Numbers)

void Array::valid()
{
    int x = 1;
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (!(A[i] >= 65 && A[i] <= 90) &&                        
            !(A[i] >= 97 && A[i] <= 122) &&
            !(A[i] >= 48 && A[i] <= 57))
        {
            x = 0;
        }
    }
    if (x == 0)
        cout << "\nYour String is not Valid" << endl;
    else
        cout << "\nYour String is  Valid" << endl;
}

// Reversing a String (Reverse Copying)

void Array::reverse1()
{
    char* B;
    int i;
    for ( i = 0; A[i] != '\0'; i++)
    {

    }
    B = new char[i];

    i--;

    int j;

    for (j = 0; i >= 0; j++, i--)
    {
        B[j] = A[i];
    }
    B[j] = '\0';
    cout << "\nReversed String : " << B << endl;
     
}

// Reversing a String (Using same string)


void Array::reverse2()
{
    int j;
    int i;
    char temp;
    for ( j = 0; A[j] != '\0'; j++)
    {

    }
    j--;
    for (i = 0; i < j; i++, j--)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    cout << "\nYour String : " << A << endl;
}

// Compairing Strings

void Array::compare()
{
    int i;
    int j;
    char* V;
    V = new char[50];
    cout << "Enter the String You want to Compare : " ;

    //cin.getline(V, 49);                                          // Unable to use getline()

    cin >> V;

    for ( i = 0, j = 0; A[i] != '\0' && V[j] != '\0'; i++, j++)
    {
        if (A[i] != V[j])
        {
            if (A[i] < V[j])
            {
                cout << "First String is Smaller" << endl;
                return;
            }

            else
            {
                cout << "First String is Bigger" << endl;
                return;
            }
        }
        
    }
    cout << "Both The Strings are Equal" << endl;
}

// Checking Palindrome

void Array::palindrome()        
{
   lower_to_upper();                                                     // To keep our Operation Case Insensitive

   int i = 0;
   int j = length();
   j--;

   for (; i < j; i++, j--)
   {
       if (A[i] != A[j])
       {
           cout << "\nGiven String is not Palindrome" << endl;
           return;
       }
   }
   cout << "\nGiven String is Palindrome" << endl;


}

// Finding Duplicates (without Hashing)

void Array::duplicates1()
{
    lower_to_upper();                                                     // To keep our Operation Case Insensitive

    int x = length();
    
    for (int i = 0; i < x - 1; i++)
    {
        int count = 1;

        if (A[i] != -1)                                                     // For Keeping track of Previously traced elements
        {
            for (int j = i + 1; j < x ; j++)
            {
                if (A[i] == A[j])
                {
                    count++;
                    A[j] = -1;                                              // Once Element is Counted it should not be traced again by A[i]
                }
            }
            if (count > 1)
            {
                cout << "\nCharcter " << A[i] << " has occured " << count << " times" << endl;
            }
        }
    }
}

// Finding Duplicates (Using Hashing)

void Array::duplicates2()
{
    upper_to_lower();                                      // For converting all alphabets to lowercase(To keep our Operation Case Insensitive)

    int x = length();

    int* H;

    H = new int[26];                                       // For all alphabets (But either small or capital)                                       

    for (int i = 0; i < 26; i++)                           // For Initializing our Dynamic Array(Hash) to 0.
        H[i] = 0;

    for (int i = 0; i < x;  i++)                           // For Tracing actual Array from User and accordingly incrementing Hash Array
        H[A[i] - 97]++;                                    // For converting Range 97-122 to 0-25 so first 97 spaces(0-96) will be saved.

    for (int i = 0; i < 26 ; i++)                          // For Tracing Hash Array to find Duplicates
    {
        if (H[i] > 1)
        {
            cout << "\nElement " << (char)(i + 97) << " has occured " << H[i] << " times" << endl;    // Retriving Back our orignal aplhabets.
        }
    }


}

// Finding Duplicates (Using Bitwise Operation)

void Array::duplicates3()
{
    upper_to_lower();                                      // For converting all alphabets to lowercase(To keep our Operation Case Insensitive)

    int H = 0;                                             // For Hashing Array 
    int M = 0;                                             // For Merging and Masking

    for (int i = 0; A[i] != '\0'; i++)
    {
        H = 1;  // Hashing Bits initialize with 1

        H = H << (A[i] - 97);                              // Suitable only for lower case 

        if ((H & M) > 0)                                   //  Checking Particular Bit is ON /OFF i.e Cehcking Duplicates i.e Merging (& operation)
        {
            cout<< '\n' << "\"" << A[i] << "\""  << " is Duplicate" << endl;
        }
        else
        {
            M = M | H;                                     // As it is Not Present in our "M" Array , Hence noting down its Presence in "M" Array i.e Masking (| operation)
        }                                                  // During Each Iteration H array is initialized with 1, but M array Remains same.
    }                               
}


// Checking Anagram (Using Hashing)

// Note :- Anagram = Two words formed with same letters eg - medical and decimal

void Array::anagram()
{
    cout << "\nNote :- Both the Strings should be in lowercase"<< endl;

    char* B; 

    B = new char[50];

    cout << "\nEnter the String you want to check : ";

    cin >> B;

    int* H;

    H = new int[26];

    for (int i = 0; i < 26; i++)                           // For Initializing our Dynamic Array(Hash) to 0.
        H[i] = 0;

    for (int i = 0 ; A[i] != '\0' ; i++)                   // For Tracing actual Array1 from User and accordingly incrementing Hash Array
        H[A[i] - 97]++;                                    // For converting Range 97-122 to 0-25 so first 97 spaces(0-96) will be saved.

    for (int i = 0; B[i] != '\0' ; i++)                          // For Tracing actual Array2 from User and accordingly Decrementing Hash Array
        H[B[i] - 97]--;                                    // For converting Range 97-122 to 0-25 so first 97 spaces(0-96) will be saved.

    for (int i = 0; i < 26; i++)                           // For Tracing Hash Array and Conforming all elements are decremented to 0
    {
        if (H[i] != 0)
        {
            cout << "\nGiven Strings are not 'Anagram'" << endl;
            return;
        }
    }
    cout << "\nGiven Strings are 'Anagram'" << endl;
}


// Finding all possible Permutations

void Array::permutation1(int k)
{
    static int F[50] = { 0 };
    static char R[50];

    if (A[k] == '\0')
    {
        R[k] = '\0';
        cout << R << endl;
    }

    else
    {
        for (int i = 0; A[i] != '\0'; i++)
        {
            if (F[i] == 0)
            {
                F[i] = 1;
                R[k] = A[i];
                permutation1(k + 1);
                F[i] = 0;
            }
        }
    }
}


/********************************************** Supportive Functions  *********************************************************/

void Array::display()
{
    cout << "\nYour String : " << A << endl;
}


