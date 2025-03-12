// dpcpp_homeworks_2_01.cpp: определяет точку входа для приложения.
//

#include "./include/decorator.h"

using namespace std;

int main()
{
	auto text_block = new Paragraph(new Text());
	auto text_block_1 = new ItalicText(new BoldText(new Text()));
	auto text_block_2 = new Reversed(new Text());
	auto text_block_3 = new Link(new Text());
	text_block->render("Paragraph");
	text_block_1->render("Hello world");
	text_block_2->render("Hello world");
	text_block_3->render("netology.ru", "Hello world");
	return 0;
}
