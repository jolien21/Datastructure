#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <cs50.h>

typedef struct node
{
    string phrase;
    struct node *next;
}
node;

node *table[26];

int hash(string phrase);

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        string phrase = get_string("Enter a new phrase: ");
        int index = hash(phrase);
        printf("%s hashes to %i\n", phrase, index);
    }
}

// TODO: return an index, 0–25, for a given phrase
int hash(string phrase)
{
  uint64_t hash = 14695981039346656037UL; // FNV offset
  for (const char *p = phrase; *p; p++) {
    hash ^= (uint64_t)(unsigned char)(*p);
    hash *= 1099511628211UL; // FNV prime
  }
  return hash % 26;
  // return toupper(phrase[0]) - 'A';
}
