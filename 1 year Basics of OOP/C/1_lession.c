#include <stdio.h>
#include <math.h>

int main()
{
    printf("Hello World\n");
    puts("My name is Bob");
    printf("My age is 21\n");
    puts("11\t22\t33\n44\t55\t66\n \\ \a");
    
    // Однострочный комментарий
    /*
        Многострочный
            комментарий
    */
    
    // Целые типы данных.
    /*
    00000000 = 0
    11111111 = 255  // (2 ^ N) - 1  
    Знаковый тип данных 
    размером 1 байт -128 +127
        min = -2^(N-1)
        max = 2^(N-1) - 1
    */
    int a = 34, b = -117; // 4 байта . тип знаковый
    unsigned int c = 15;
    short s = 12; // 2 байта.
    // short = signed short = short int = signed short int 
    printf(" a = %d b = %d c = %u\n", a, b, c );
    printf(" %o %X\n", c, c);
    /*
        Операторы сравнения:
        >, <, >=, <=, ==, !=
        
        0 - Ложь
        Все что не 0 - Истина
    */
    printf("%d %d", 10 == 15, 10 > 4); 
    // Логическая операторы.
    /*
        И  ИЛИ  НЕ
        &&  ||  !
        true && true => true
        false || false => false
        
        !true = false
        !false = true
    */
    printf(" %d %d %d", (10<15&&3==3), (7>5||4<2), !(7<5));
    /*
        Арифметические операторы.
        *, /, +, -, % не применяется к типам float / double
    */
    printf("\n%d %d\n", 10/3, 7%4);
    // +=, -=, /=, *=, %=
    a+=10; // a = a + 10;
    
    printf("%7d%7d\t%07d\n", 11, 1234, 568);
    printf("%-7d%-7d%-7d\n", 11, 1234, 568);
    
    // Тернарный оператор.
    /*
        (Условие)? выр1:выр2;
    */
    int result = (a%2 != 0) ? (10+20):(b=5);
    printf("a = %d result = %d b = %d", a, result, b);
    
    /*
        F(X) = 0,  X = 0
        F(X) = 1,  X > 0
        F(X) = -1, X < 0
    */
    int x = 12, F;
    (x == 0) ? F=0 : ( (x > 0) ? F=1 : (F=-1));
    printf("\nF(X) = %d\n", F);
    
    
    if(x==0) F = 0;
    else if(x>0) F = 1;
    else F = -1;
    
    int a1 = 5, b1 = 10, c1 = 15;
    int max =  (a1>b1 && a1>c1)? a1:( (b1>c1)?b1:c1);
    printf("\nMAX = %d\n", max);
    
    /*
        float 4 байта.
        double 8 байтов.
    */
    double d1 = 65.23;
    float f1 = 435.6;
    printf("%.2f %.3lf\n", f1, d1);
   //printf("%.3e\n", f1);
    //printf("%.3E\n", f1);
    printf("%15.3e%15.4E\n", f1, f1);
    
    int a11 = 7;
    float f11 = 3;
    float r11 = a11/f11;
    printf("%.2f %lf %f", r11, 7./3, 7/3.f);
    
    /*
        Не применяются к типам float/double
        Постфиксный инкремент X++
        Постфиксный декремент X--
        
        Префиксный инкремент ++X
        Префиксный декремент --X
    */
    
    int y = 5;
    int k = ++y; // k = 5 y = 6
    printf("\nk = %d y = %d", k, y);
    y = 5;
    
    k = y++ + 10;    
    printf("\nk = %d y = %d", k, y); // 15 6
    
                                     
    /*if(15>10) {
        puts(" IF ");
        if(4>2){
            // инстуркция 1
            // инстуркция 2
        }
        else // инстуркция 3
        a = 100;
    }   
    else {
        if()
        puts(" ELSE ");
    }
    */
    return 0;
}

