#ifndef BL_H
#define BL_H

int bl_book_add(const char *book_name, const char *author_name, int year,
                const char *publisher, const char *category);
int bl_book_remove(const char *book_name);
int bl_book_list(void);
int bl_book_list_borrowed(void);
int bl_book_list_by_author(const char *author_name);
int bl_book_borrow(const char *book_name, const char *borrower_name);
int bl_book_return(const char *book_name);

int bl_author_add(const char *author_name);
int bl_author_remove(const char *author_name);
int bl_author_list(void);

int bl_category_add(const char *category_name);
int bl_category_remove(const char *category_name);
int bl_category_list(void);

int bl_publisher_add(const char *publisher_name);
int bl_publisher_remove(const char *publisher_name);
int bl_publisher_list(void);

#endif // BL_H
