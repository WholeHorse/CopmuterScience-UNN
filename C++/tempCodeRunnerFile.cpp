Complex& operator=(const Complex & r){ 
        if(re != r.re && im != r.im){
            re = r.re;
            im = r.im;
            }
        return *this;
    }
