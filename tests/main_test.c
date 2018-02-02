/*
** EPITECH PROJECT, 2018
** Project My_world Testing
** File description:
** Unit Testing Project My_world
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "main.h"

void main_redirect_stdout(void)
{
	cr_redirect_stdout();
}

Test(My_world, Return_Value_Test)
{
	cr_assert_eq("Function to test()", "Int Output..");
}