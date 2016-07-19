class revStr{
public:
    void reverse(char *str){
        char *end = str;
        char tmp;
        // find end of string
        if(str){
            while(*end){
                end++;
            }
            end--;              // go one char back, the null termination

            while(str < end){
                tmp = *str;
                *str = *end;
                *end = tmp;
                str++;
                end--;
            }
        }
    }
};