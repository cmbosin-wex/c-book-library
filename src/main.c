

/**
 * Book library application
 *
 * Commands
 * book-library book add <book-name> <author-name> <year> <publisher> <category>
 * book-library book remove <book-name>
 * book-library book list
 * book-library book list-borrowed
 * book-library book list-by-author <author-name>
 * book-library book borrow <book-name> <borrower-name>
 * book-library book return <book-name>
 *
 * book-library author add <author-name>
 * book-library author remove <author-name>
 * book-library author list
 *
 * book-library category add <category-name>
 * book-library category remove <category-name>
 * book-library category list
 *
 * book-library publisher add <publisher-name>
 * book-library publisher remove <publisher-name>
 * book-library publisher list
 *
 * book-library help
 */

#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "bl.h"

void usage(void);

int main(int argc, char *const * argv) {
    int opt;
    int option_index = 0;
    static struct option long_options[] = {
        {"book", required_argument, 0, 'b'},
        {"author", required_argument, 0, 'a'},
        {"category", required_argument, 0, 'c'},
        {"publisher", required_argument, 0, 'p'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    if (argc < 2) {
        usage();
        return 1;
    }

    while ((opt = getopt_long(argc, argv, "b:a:c:p:h", long_options, &option_index)) != -1) {
        switch (opt) {
            case 'b':
                if (strcmp(optarg, "add") == 0) {
                    bl_book_add(argv[2], argv[3], atoi(argv[4]), argv[5], argv[6]);
                } else if (strcmp(optarg, "remove") == 0) {
                    bl_book_remove(argv[2]);
                } else if (strcmp(optarg, "list") == 0) {
                    bl_book_list();
                } else if (strcmp(optarg, "list-borrowed") == 0) {
                    bl_book_list_borrowed();
                } else if (strcmp(optarg, "list-by-author") == 0) {
                    bl_book_list_by_author(argv[2]);
                } else if (strcmp(optarg, "borrow") == 0) {
                    bl_book_borrow(argv[2], argv[3]);
                } else if (strcmp(optarg, "return") == 0) {
                    bl_book_return(argv[2]);
                }
                break;
            case 'a':
                if (strcmp(optarg, "add") == 0) {
                    bl_author_add(argv[2]);
                } else if (strcmp(optarg, "remove") == 0) {
                    bl_author_remove(argv[2]);
                } else if (strcmp(optarg, "list") == 0) {
                    bl_author_list();
                }
                break;
            case 'c':
                if (strcmp(optarg, "add") == 0) {
                    bl_category_add(argv[2]);
                } else if (strcmp(optarg, "remove") == 0) {
                    bl_category_remove(argv[2]);
                } else if (strcmp(optarg, "list") == 0) {
                    bl_category_list();
                }
                break;
            case 'p':
                if (strcmp(optarg, "add") == 0) {
                    bl_publisher_add(argv[2]);
                } else if (strcmp(optarg, "remove") == 0) {
                    bl_publisher_remove(argv[2]);
                } else if (strcmp(optarg, "list") == 0) {
                    bl_publisher_list();
                }
                break;
            case 'h':
            default:
                usage();
                return 1;
        }
    }

    return 0;
}

void usage(void) {
    printf("Book library application\n\n");
    printf("Usage book-library [command] [options]\n\n");
    printf("Commands\n");
    printf("  book         Book commands\n");
    printf("  author       Author commands\n");
    printf("  category     Category commands\n");
    printf("  publisher    Publisher commands\n");
    printf("  help         Show this help\n\n");
    printf("Book commands\n");
    printf("  add <book-name> <author-name> <year> <publisher> <category>\n");
    printf("  remove <book-name>\n");
    printf("  list\n");
    printf("  list-borrowed\n");
    printf("  list-by-author <author-name>\n");
    printf("  borrow <book-name> <borrower-name>\n");
    printf("  return <book-name>\n\n");
    printf("Author commands\n");
    printf("  add <author-name>\n");
    printf("  remove <author-name>\n");
    printf("  list\n\n");
    printf("Category commands\n");
    printf("  add <category-name>\n");
    printf("  remove <category-name>\n");
    printf("  list\n\n");
    printf("Publisher commands\n");
    printf("  add <publisher-name>\n");
    printf("  remove <publisher-name>\n");
    printf("  list\n\n");
}
