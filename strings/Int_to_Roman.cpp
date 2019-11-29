// interview bit integer to roman
string number_to_roman( int A)
{
    string M[]  = {"",  "M","MM", "MMM"};
    string C [] = {"", "C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string X [] = {"", "X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string I [] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    string result  = "";
    result = M[A/1000] + C[(A%1000)/100] + X[(A%100)/10] + I[A%10];
    return result;

}
int main(int argc, const char * argv[]) {
    string a ;
    int num; cin>>num;
    a = number_to_roman(num);
    cout<<a<<endl;





}
