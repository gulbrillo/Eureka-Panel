/*
This module returns the HTML footer
*/

int settings_theme()
{

char *t_cards_sel = " ";
char *t_metropolis_sel = " ";
char *t_candyland_sel = " ";
char *t_bluescience_sel = " ";
char *t_ponytail_sel = " ";
char *t_browncoats_sel = " ";

char settings_theme[1024];
read_config_var("Webpanel", "theme", settings_theme);

if (compStr(settings_theme, "metropolis", 1024)) {
	t_metropolis_sel="checked";
	}
else if (compStr(settings_theme, "candyland", 1024)) {
	t_candyland_sel="checked";
        }
else if (compStr(settings_theme, "bluescience", 1024)) {
        t_bluescience_sel="checked";
        }
else if (compStr(settings_theme, "ponytail", 1024)) {
        t_ponytail_sel="checked";
        }
else if (compStr(settings_theme, "browncoats", 1024)) {
        t_browncoats_sel="checked";
        }
else	{
	t_cards_sel = "checked";
        }

printf("<ul><form id=\"themesForm\"><input type=\"hidden\" name=\"action\" value=\"update\">");
printf("<li><input type=\"radio\" %s name=\"Webpanel/theme\" id=\"cards_theme\" value=\"cards\"><label for=\"cards_theme\" class=\"%s\">Cards (default)</label></li>", t_cards_sel, t_cards_sel);
printf("<li><input type=\"radio\" %s name=\"Webpanel/theme\" id=\"metropolis_theme\" value=\"metropolis\"><label for=\"metropolis_theme\" class=\"%s\">Metropolis</label></li>", t_metropolis_sel, t_metropolis_sel);
printf("<li><input type=\"radio\" %s name=\"Webpanel/theme\" id=\"candyland_theme\" value=\"candyland\"><label for=\"candyland_theme\" class=\"%s\">Candyland</label></li>", t_candyland_sel, t_candyland_sel);
printf("<li><input type=\"radio\" %s name=\"Webpanel/theme\" id=\"bluescience_theme\" value=\"bluescience\"><label for=\"bluescience_theme\" class=\"%s\">Bluescience</label></li>", t_bluescience_sel, t_bluescience_sel);
printf("<li><input type=\"radio\" %s name=\"Webpanel/theme\" id=\"ponytail_theme\" value=\"ponytail\"><label for=\"ponytail_theme\" class=\"%s\">Ponytail</label></li>", t_ponytail_sel, t_ponytail_sel);
printf("<li><input type=\"radio\" %s name=\"Webpanel/theme\" id=\"browncoats_theme\" value=\"browncoats\"><label for=\"browncoats_theme\" class=\"%s\">Browncoats</label></li>", t_browncoats_sel, t_browncoats_sel);
printf("</form></ul>Themes");

}
