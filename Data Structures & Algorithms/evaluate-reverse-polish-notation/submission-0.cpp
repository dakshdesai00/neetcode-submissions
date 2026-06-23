class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       int lastNum = stoi(tokens[0]);
       for(int i = 1; i < tokens.size(); i+=2){
            int num = stoi(tokens[i]);
            if(tokens[i+1] == "+"){
                lastNum += num;
            }else if(tokens[i+1] == "-"){
                lastNum -= num;
            }
            else if(tokens[i+1] == "*"){
                lastNum *= num;
            }
            else if(tokens[i+1] == "/"){
                lastNum /= num;
            }
       } 
       return lastNum;
    }
};
