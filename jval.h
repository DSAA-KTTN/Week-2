
// --------------------------------
typedef union 
{
    int i;
    long l;
    float f;
    double d;
    char c;
    void *v;
    char *s;
} jval;
// --------------------------------

// --------------------------------
// Gán giá trị cho jval
jval new_jval_i(int i)
{
    jval jv;
    jv.i = i;
    return jv;
}

jval new_jval_l(long l)
{
    jval jv;
    jv.l = l;
    return jv;
}

jval new_jval_f(float f)
{
    jval jv;
    jv.f = f;
    return jv;
}

jval new_jval_d(double d)
{
    jval jv;
    jv.d = d;
    return jv;
}

jval new_jval_c(char c)
{
    jval jv;
    jv.c = c;
    return jv;
}

jval new_jval_v(void *v)
{
    jval jv;
    jv.v = v;
    return jv;
}

jval new_jval_s(char *s)
{
    jval jv;
    jv.s = s;
    return jv;
}
// --------------------------------

// --------------------------------
// Lấy giá trị của jval
int jval_i(jval jv)
{
    return jv.i;
}

long jval_l(jval jv)
{
    return jv.l;
}

float jval_f(jval jv)
{
    return jv.f;
}

double jval_d(jval jv)
{
    return jv.d;
}

char jval_c(jval jv)
{
    return jv.c;
}

void *jval_v(jval jv)
{
    return jv.v;
}

char *jval_s(jval jv)
{
    return jv.s;
}
// --------------------------------

// --------------------------------
// Các loại so sánh
int compare_i(jval *a, jval *b)
{
    if (jval_i(*a) == jval_i(*b))
        return 0;
	else if (jval_i(*a) < jval_i(*b))
        return -1;
	else return 1;
}
// --------------------------------
