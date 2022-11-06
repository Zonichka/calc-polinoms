#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct polinom_t {	//Объявление структуры
    double* coef;
    size_t n;
} polinom_t;

typedef char* lexeme_t;

typedef struct tree_t {	//Объявление дерева
    char* lex;
    struct tree_t* left;
    struct tree_t* right;
} tree_t;

int is_ariphmetic(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int is_bracket(char c) {
    return c == '(' || c == ')';
}
int priority(char c) {
    switch (c) {
        case '+':
        case '-':
            return 0;
        case '*':
        case '/':
            return 1;
        default:
            return 2;
    }
}

lexeme_t* parse(size_t* size) {	// Функция, необходимая для разделения на лексемы введенного полинома
    *size = 0;
    size_t capacity = 1;
    lexeme_t* lexemes = (lexeme_t*)malloc(sizeof(lexeme_t));
    char c = getchar();
    while (c != '\n') {
        lexeme_t lexeme = NULL;
        if (is_ariphmetic(c) || is_bracket(c)) {
            switch (c) {
                case '+':
                    lexeme = "+";
                    break;
                case '-':
                    lexeme = "-";
                    break;
                case '*':
                    lexeme = "*";
                    break;
                case '/':
                    lexeme = "/";
                    break;
                case '(':
                    lexeme = "(";
                    break;
                case ')':
                    lexeme = ")";
                    break;
            }
            lexemes[(*size)++] = lexeme;
            if (*size >= capacity)
                lexemes = (lexeme_t*)realloc(lexemes, (capacity *= 2) * sizeof(lexeme_t));
        }
        else if (c != ' ') {
            size_t s_size = 0;
            size_t s_capacity = 2;
            char* s = (char*)malloc(s_capacity * sizeof(char));
            while (c != '\n' && c != ')') {
                if (c != ' ') {
                    s[s_size++] = c;
                    if (s_size >= s_capacity)
                        s = (char*)realloc(s, (s_capacity *= 2) * sizeof(char));
                }
                c = getchar();
            }
            s[s_size] = '\0';
            lexemes[*size - 1] = s;
        }
        c = getchar();
    }
    return lexemes;
}

tree_t* make_tree(lexeme_t* expr, int first, int last) {	// Создание дерева и работа с приоритетом операций
    tree_t* tree = (tree_t*)malloc(sizeof(tree_t));
    int k = 0, minPriority = 2;
    int brackets = 0;
    for (int i = first; i <= last; i++) {
        if (expr[i][0] == '(')
            brackets++;
        else if (expr[i][0] == ')')
            brackets--;
        else if (brackets <= 0) {
            int curPriority = priority(expr[i][0]);

            if (curPriority <= minPriority) {
                minPriority = curPriority;
                k = i;
            }
        }
    }
    if (minPriority == 2 && expr[first][0] == '(' && expr[last][0] == ')') {
        free(tree);
        return make_tree(expr, first + 1, last - 1);
    }
    else if (minPriority == 2) {
        tree->lex = expr[first];
        tree->left = NULL;
        tree->right = NULL;
        return tree;
    }
    tree->lex = expr[k];
    tree->left = make_tree(expr, first, k - 1);
    tree->right = make_tree(expr, k + 1, last);
    return tree;
}

// вывод дерева в обратной польской записи
void print_tree(tree_t* tree) {
    if (!tree)
        return;
    printf("%s ", tree->lex);
    print_tree(tree->left);
    print_tree(tree->right);
}

void print_polinom(polinom_t p) {	//Вывод результата
    for (int i = p.n; i >= 0; i--) {
        if (p.coef[i] != 0) {
            if (i < p.n)
                printf("%c", p.coef[i] > 0 ? '+' : '-');

            if (p.coef[i] != 1.0 || i == 0)
                printf("%.1lf", p.coef[i] < 0 ? -p.coef[i] : p.coef[i]);
            printf("%s", i > 1 ? "x^" : i == 1 ? "x" : "");
            if (i > 1)
                printf("%d", i);
        }
    }
    printf("\n");
}

char** split(char* s, size_t* size) {	// Разделение на элементы
    size_t capacity = 1;
    *size = 0;
    char** elems = (char**)malloc(capacity * sizeof(char*));
    size_t i = 0;
    while (s[i]) {
        size_t elem_size = 0;
        size_t elem_capacity = 2;
        char* elem = (char*)malloc(elem_capacity * sizeof(char));
        if (s[i] != '+')
            elem[elem_size++] = s[i];
        i++;
        while (s[i] && s[i] != '+' && s[i] != '-') {
            elem[elem_size++] = s[i];
            if (elem_size >= elem_capacity)
                elem = (char*)realloc(elem, (elem_capacity *= 2) * sizeof(char));
            i++;
        }
        elem[elem_size] = '\0';
        elems[(*size)++] = elem;
        if (*size >= capacity)
            elems = (char**)realloc(elems, (capacity *= 2) * sizeof(char*));
    }
    return elems;
}

polinom_t get_polinom(char* s) {	//Обработка задач для лексем
    size_t power = 0;
    for (size_t i = 0; s[i]; i++) {
        if (s[i] == 'x') {
            int n = 1;
            if (s[i + 1] == '^')
                sscanf_s(s + i + 2, "%d", &n);
            if (n > power)
                power = n;
        }
    }
    polinom_t polinom;
    polinom.n = power;
    polinom.coef = (double*)calloc(power + 1, sizeof(double));
    size_t len;
    char** elems = split(s, &len);
    for (size_t i = 0; i < len; i++) {
        double a;
        size_t n;
        if (elems[i][0] == 'x') {
            n = 1;
            if (elems[i][1] == '^')
                sscanf_s(elems[i] + 2, "%ld", &n);
            polinom.coef[n] = 1;
        }
        else if (elems[i][0] == '-' && elems[i][1] == 'x') {
            n = 1;
            if (elems[i][2] == '^')
                sscanf_s(elems[i] + 3, "%ld", &n);

            polinom.coef[n] = -1;
        }
        else {
            char* res = strstr(elems[i], "x");
            n = 0;
            sscanf_s(elems[i], "%lf", &a);
            if (res) {
                n = 1;
                if (res[1] == '^')
                    sscanf_s(res + 2, "%ld", &n);
            }
            polinom.coef[n] = a;
        }
        free(elems[i]);
    }
    free(elems);
    return polinom;
}

polinom_t add(polinom_t p1, polinom_t p2) {	//Сложение двух участков
    polinom_t p;
    p.n = p1.n > p2.n ? p1.n : p2.n;
    p.coef = (double*)calloc(p.n + 1, sizeof(double));
    for (size_t i = 0; i <= p1.n; i++)
        p.coef[i] += p1.coef[i];
    for (size_t i = 0; i <= p2.n; i++)
        p.coef[i] += p2.coef[i];
    while (p.coef[p.n] == 0 && p.n > 0)
        p.n--;
    p.coef = (double*)realloc(p.coef, (p.n + 1) * sizeof(double));
    return p;
}

polinom_t sub(polinom_t p1, polinom_t p2) {	//Вычитание двух участков
    polinom_t p;
    p.n = p1.n > p2.n ? p1.n : p2.n;
    p.coef = (double*)calloc(p.n + 1, sizeof(double));
    for (size_t i = 0; i <= p1.n; i++)
        p.coef[i] += p1.coef[i];
    for (size_t i = 0; i <= p2.n; i++)
        p.coef[i] -= p2.coef[i];
    while (p.coef[p.n] == 0 && p.n > 0)
        p.n--;
    p.coef = (double*)realloc(p.coef, (p.n + 1) * sizeof(double));
    return p;
}
polinom_t mult(polinom_t p1, polinom_t p2) {	    //Умножение двух участков
    polinom_t p;
    p.n = p1.n + p2.n;
    p.coef = (double*)calloc(p.n + 1, sizeof(double));
    for (size_t i = 0; i <= p1.n; i++)
        for (size_t j = 0; j <= p2.n; j++)
            p.coef[i + j] += p1.coef[i] * p2.coef[j];
    while (p.coef[p.n] == 0 && p.n > 0)
        p.n--;
    p.coef = (double*)realloc(p.coef, (p.n + 1) * sizeof(double));
    return p;
}

polinom_t divide(polinom_t p1, polinom_t p2) {	//Деление двух участков
    polinom_t p;
    p.n = p1.n > p2.n ? p1.n - p2.n : 0;
    p.coef = (double*)calloc(p.n + 1, sizeof(double));
    while (p1.n > 0 && p1.n >= p2.n) {
        double a = p1.coef[p1.n] / p2.coef[p2.n];
        p.coef[p1.n - p2.n] = a;
        polinom_t tmp;
        tmp.n = p1.n;
        tmp.coef = (double*)calloc(tmp.n + 1, sizeof(double));
        for (size_t j = 0; j <= p2.n; j++)
            tmp.coef[p1.n - p2.n + j] = a * p2.coef[j];
        p1 = sub(p1, tmp);
        free(tmp.coef);
    }
    return p;
}

polinom_t calculate(tree_t* tree) { // Произведение операций над лексемами.
    if (!tree->left) {
        polinom_t result = get_polinom(tree->lex);
        free(tree);
        return result;
    }
    polinom_t left = calculate(tree->left);
    polinom_t right = calculate(tree->right);
    polinom_t result;
    switch (tree->lex[0]) {
        case '+':
            result = add(left, right);
            break;
        case '-':
            result = sub(left, right);
            break;

        case '*':
            result = mult(left, right);
            break;
        case '/':
            result = divide(left, right);
            break;
    }

    free(left.coef);
    free(right.coef);
    free(tree);

    return result;
}

int main() {
    printf("Enter expression: ");
    size_t size;
    lexeme_t* lexemes = parse(&size);
    tree_t* tree = make_tree(lexemes, 0, size - 1);
    polinom_t res = calculate(tree);
    printf("Result: ");
    print_polinom(res);
    free(res.coef);
    for (size_t i = 0; i < size; i++)
        if (!is_bracket(lexemes[i][0]) && !is_ariphmetic(lexemes[i][0]))
            free(lexemes[i]);	// Освобождение динамически выделенной памяти
    free(lexemes);

    return 0;
}