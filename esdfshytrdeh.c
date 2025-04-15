#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Token types
typedef enum {
    TOK_IDENTIFIER,
    TOK_NUMBER,
    TOK_ASSIGN,
    TOK_PLUS,
    TOK_MINUS,
    TOK_MUL,
    TOK_DIV,
    TOK_LPAREN,
    TOK_RPAREN,
    TOK_SEMICOLON,
    TOK_EOF,
    TOK_ERROR
} TokenType;

// Symbol table structure
typedef struct {
    char *name;
    int declared;
} Symbol;

// Global variables
char *source;
int pos = 0;
int line = 1;
TokenType current_token;
char lexeme[100];
Symbol sym_table[100];
int sym_count = 0;

// Function to return string representation of token
const char *token_name(TokenType token) {
    switch (token) {
        case TOK_IDENTIFIER: return "Identifier";
        case TOK_NUMBER: return "Number";
        case TOK_ASSIGN: return "Assignment";
        case TOK_PLUS: return "Plus";
        case TOK_MINUS: return "Minus";
        case TOK_MUL: return "Multiplication";
        case TOK_DIV: return "Division";
        case TOK_LPAREN: return "Left Parenthesis";
        case TOK_RPAREN: return "Right Parenthesis";
        case TOK_SEMICOLON: return "Semicolon";
        case TOK_EOF: return "End of File";
        case TOK_ERROR: return "Error";
        default: return "Unknown";
    }
}

// Error handling functions
void error(const char *msg) {
    fprintf(stderr, "Error (line %d): %s\n", line, msg);
}

void expected(const char *what) {
    fprintf(stderr, "Error (line %d): Expected %s\n", line, what);
}

// Lexical analyzer
TokenType next_token() {
    static char ch = ' ';
    
    while (isspace(ch)) {
        if (ch == '\n') line++;
        ch = source[pos++];
    }

    if (ch == '\0') return TOK_EOF;

    // Identifier
    if (isalpha(ch)) {
        int i = 0;
        while (isalnum(ch)) {
            lexeme[i++] = ch;
            ch = source[pos++];
        }
        lexeme[i] = '\0';
        return TOK_IDENTIFIER;
    }

    // Number
    if (isdigit(ch)) {
        int i = 0;
        while (isdigit(ch)) {
            lexeme[i++] = ch;
            ch = source[pos++];
        }
        lexeme[i] = '\0';
        return TOK_NUMBER;
    }

    // Operators & Symbols
    switch (ch) {
        case '=': ch = source[pos++]; return TOK_ASSIGN;
        case '+': ch = source[pos++]; return TOK_PLUS;
        case '-': ch = source[pos++]; return TOK_MINUS;
        case '*': ch = source[pos++]; return TOK_MUL;
        case '/': ch = source[pos++]; return TOK_DIV;
        case '(': ch = source[pos++]; return TOK_LPAREN;
        case ')': ch = source[pos++]; return TOK_RPAREN;
        case ';': ch = source[pos++]; return TOK_SEMICOLON;
        default:
            error("Invalid character");
            ch = source[pos++];
            return TOK_ERROR;
    }
}

// Symbol table management
Symbol* find_symbol(const char *name) {
    for (int i = 0; i < sym_count; i++) {
        if (strcmp(sym_table[i].name, name) == 0)
            return &sym_table[i];
    }
    return NULL;
}

void declare_symbol(const char *name) {
    if (find_symbol(name)) {
        error("Duplicate identifier declaration");
        return;
    }
    sym_table[sym_count].name = strdup(name);
    sym_table[sym_count].declared = 1;
    sym_count++;
}

// Parser functions
void match(TokenType expected) {
    if (current_token == expected) {
        current_token = next_token();
    } else {
        error(token_name(expected));

        // Error recovery: Skip tokens until the next semicolon
        while (current_token != TOK_SEMICOLON && current_token != TOK_EOF) {
            current_token = next_token();
        }
    }
}

void parse_expression();
void parse_statement() {
    if (current_token == TOK_IDENTIFIER) {
        // Check if identifier is declared
        if (!find_symbol(lexeme)) {
            error("Undeclared identifier. Auto-declaring.");
            declare_symbol(lexeme);
        }
        match(TOK_IDENTIFIER);
        match(TOK_ASSIGN);
        parse_expression();
    } else {
        expected("identifier");
    }
    match(TOK_SEMICOLON);
}

void parse_expression() {
    parse_term();
    while (current_token == TOK_PLUS || current_token == TOK_MINUS) {
        match(current_token);
        parse_term();
    }
}

void parse_term() {
    parse_factor();
    while (current_token == TOK_MUL || current_token == TOK_DIV) {
        match(current_token);
        parse_factor();
    }
}

void parse_factor() {
    if (current_token == TOK_IDENTIFIER) {
        match(TOK_IDENTIFIER);
    } else if (current_token == TOK_NUMBER) {
        match(TOK_NUMBER);
    } else if (current_token == TOK_LPAREN) {
        match(TOK_LPAREN);
        parse_expression();
        match(TOK_RPAREN);
    } else {
        expected("identifier, number, or '('");
    }
}

void parse_program() {
    current_token = next_token();
    while (current_token != TOK_EOF) {
        parse_statement();
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <source_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    source = malloc(size + 1);
    if (!source) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(fp);
        return 1;
    }

    fread(source, 1, size, fp);
    source[size] = '\0';
    fclose(fp);

    parse_program();

    // Free allocated symbol names
    for (int i = 0; i < sym_count; i++) {
        free(sym_table[i].name);
    }
    free(source);
    
    return 0;
}