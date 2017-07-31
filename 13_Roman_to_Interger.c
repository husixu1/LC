int romanToInt(char* s) {
    char *p = s;
    for(; *p; ++p);
    int last = 0;
    int result = 0;

    while(p!=s){
        switch(*(--p)){
            case 'I':
                if(last > 1)
                    result-=1;
                else
                    result+=1;
                last = 1;
                break;
            case 'V':
                result+=5;
                last = 5;
                break;
            case 'X':
                if(last > 10)
                    result-=10;
                else
                    result+=10;
                last = 10;
                break;
            case 'L':
                result += 50;
                last = 50;
                break;
            case 'C':
                if(last > 100)
                    result-=100;
                else
                    result+=100;
                last = 100;
                break;
            case 'D':
                result+=500;
                last = 500;
                break;
            case 'M':
                result+=1000;
                last = 1000;
                break;
        }
    }
    return result;
}
