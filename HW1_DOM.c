#include <stdio.h>
#include <locale.h>

void printHome() {
	puts("               _____________________    ");
	puts("              /                    /\\    ");
	puts("             /                    /  \\    ");
	puts("          __/                    /    \\__    ");
	puts("         / /                    /       /   ");
	puts("        / /                    /       /   ");
	puts("       / /                    /       /|   ");
	puts("      / /                    /       /||   ");
	puts("     / /                    /       / ||     ");
	puts("    / /                    /       /  ||  ");
	puts("   / /____________________/       /   || ");
	puts("  / //                   \\\\      /    ||  ");
	puts(" / //                     \\\\    /     ||");
	puts("/_//_______________________\\\\__/      ||");
	puts("  ||                       ||        /");
	puts("  ||                       ||       /");
	puts("  ||        _______        ||      /");
	puts("  ||        |_____|        ||     /");
	puts("  ||        |  |  |        ||    /");
	puts("  ||        |  |  |        ||   /");
	puts("  ||        |__|__|        ||  /");
	puts("  ||                       || /");
	puts("  ||_______________________||/");
}

void main()
{
	setlocale(LC_ALL, "ru-RU");
	printHome();
}
