#include <unistd.h>
#include <string.h>
#include <orbis/SystemService.h>
#include <mini18n.h>

#include "orbisPad.h"
#include "menu.h"
#include "menu_gui.h"
#include "common.h"

extern int close_app;

int menu_id = 0;
int menu_sel = 0;

void initMenuOptions(void)
{
}

static void doMainMenu(void)
{
	menu_sel = 0;

	if (orbisPadGetButtonPressed(ORBIS_PAD_BUTTON_CROSS))
	{
		sceSystemServiceNavigateUri(0, "https://movie.vodu.me/");
		return;
	}
	else if(orbisPadGetButtonPressed(ORBIS_PAD_BUTTON_CIRCLE) && show_dialog(DIALOG_TYPE_YESNO, _("Exit to XMB?")))
	{
		close_app = 1;
	}
	
	Draw_MainMenu();
}

void drawScene(void)
{
	doMainMenu();
}
