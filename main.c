#include "printf.h"

int				main(void)
{
	//ft_printf("_%c_%-c_%10c_%-10c_", 1568, 68843, 48654, 46812);
	//printf("\n%10c_%-10c", 192, 82);
	//ft_printf("%10u_%-10u_%-010u", 123, 456, 789);
	//printf("\n%10u_%-10u_%-010u", 123, 456, 789);
	//ft_printf("%10p_%10p_%10p", NULL, "COUCOU", "COUCOU");
	//printf("\n");
	//printf("%10p_%10p_%10p", NULL, "COUCOU", "COUCOU");
	long double d = 1.0;
	long double e = 2.0;
	long double f = -2.0;
	long double g = 3.0;
	long double h = 0.5;
	long double i = (long double)0.0 * ((long double)-5.0 / (long double)0.0);
	double a = 0.0 * (5.0 / 0.0);
	//ft_printf("%Lf\n%Lf\n%Lf\n%Lf\n%Lf\n%Lf\n", d, e, f, g, h);
	//ft_printf("%f\n%f\n%f\n%f\n%f\n%f\n", 1.0, 2.0, -2.0, 3.0, 0.5, a);
	
	//ft_printf("%1000000d\n", 52);
	//printf("%100000d\n", 52);
	
	// pas afficher de 0 devant
	//ft_printf("%0#10x\n", 12345);
	//printf("%0#10x\n", 12345);

	ft_printf("%0#10.x\n", 12345);
	printf("%0#10.x\n", 12345);

	//gerer mfw trop grand -> ignorer (sinon bus error)
	
	//printf("%Lf", (long double)0.0 * ((long double)-5.0 / (long double)0.0));
	
	//a gerer
	//ft_printf("%.d", 0);
	//printf("\n%.d", 0);

	//a gerer (afficher l'espace meme sans le 0)
	//ft_printf("% .d bonjour", 0);
	//printf("\n% .d bonjour", 0);

	//en cas d'erreur, renvoyer -1
	return (0);
}
