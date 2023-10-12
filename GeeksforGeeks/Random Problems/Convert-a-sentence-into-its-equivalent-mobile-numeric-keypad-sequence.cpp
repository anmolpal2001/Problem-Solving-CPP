Ques : https://practice.geeksforgeeks.org/problems/convert-a-sentence-into-its-equivalent-mobile-numeric-keypad-sequence0547/1

Solution : 
string printSequence(string S)
{
    string ans="";
    for(int i=0;i<S.length();i++)
    {
        char ch = S[i];
        switch(ch)
        {
            case 'C': ans.push_back('2');
            case 'B' : ans.push_back('2');
            case 'A' : ans.push_back('2'); 
            break;
            case 'F' : ans.push_back('3');
            case 'E' : ans.push_back('3');
            case 'D' : ans.push_back('3'); 
            break;
            case 'I' : ans.push_back('4');
            case 'H' : ans.push_back('4'); 
            case 'G' : ans.push_back('4');
            break;
            case 'L' : ans.push_back('5');
            case 'K' : ans.push_back('5');
            case 'J' : ans.push_back('5'); 
            break;
            case 'O' : ans.push_back('6');
            case 'N' : ans.push_back('6');
            case 'M' : ans.push_back('6'); 
            break;
            case 'S' : ans.push_back('7');
            case 'R' : ans.push_back('7');
            case 'Q' : ans.push_back('7');
            case 'P' : ans.push_back('7'); 
            break;
            case 'V' : ans.push_back('8');
            case 'U' : ans.push_back('8');
            case 'T' : ans.push_back('8'); 
            break;
            case 'Z' : ans.push_back('9');
            case 'Y' : ans.push_back('9');
            case 'X' : ans.push_back('9');
            case 'W' : ans.push_back('9'); 
            break;
            default : ans+='0'; 
            break;
        }
    }
    return ans;
}
