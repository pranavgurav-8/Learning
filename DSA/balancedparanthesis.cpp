#include <iostream>
#include <stack>

bool checkBalancedParanthesis(std::string& s){
    std::stack<char> stk;
    bool res = false;
    for(int i=0; i<s.length(); i++){
        if(stk.empty()){
            stk.push(s[i]);
            continue;
        }
        if(s[i]=='{' || s[i]=='(' || s[i]=='['){
            stk.push(s[i]);
            continue;
        }
        else if(s[i]=='}' || s[i]==')' || s[i]==']'){
            if(stk.empty()){
                std::cout<<"hel"<<std::endl;
                res = false;
                break;
            }
            char ch = stk.top();
            stk.pop();
            if((ch != '(' && s[i] == ')') || (ch != '{' && s[i]=='}') || (ch != '[' && s[i]==']') ){
                
                res = false;
                std::cout<<i<<std::endl;
                break;
            }
        }
        
    }
    
    if(stk.empty()){
        std::cout<<"balanced paranthesis"<<std::endl;
        res = true;
    }
    return res;
    
}
int main() {
    std::string s = "{{{{{{{[{}]}}}}}}}";
    std::cout<<checkBalancedParanthesis(s)<<std::endl;
    return 0;
}