#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
struct Book {
	std::string author;
	std::string category;
	unsigned int pages;

	std::string getAuthor() const
	{
		return author;
	}

	std::string getCategory() const
	{
		return category;
	}

	unsigned int getPages() const
	{
		return pages;
	}
	Book() = default;
	
	Book(const std::string& p_author, const std::string& p_category,
		 unsigned int p_pages)
		: author(p_author), category(p_category), pages(p_pages)
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Book& b)
	{
		out << ", Author: " << b.getAuthor()
			<< ", Category: " << b.getCategory() << ", Pages: " << b.getPages();
		return out;
	}
};

#endif // BOOK_H
