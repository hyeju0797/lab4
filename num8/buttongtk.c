#include <gtk/gtk.h>
/* 콜백 함수 */
static void destroy(GtkWidget *widget, gpointer data )
{
	gtk_widget_destroy (data);
}
static void activate(GtkApplication *app, gpointer data )
{
	GtkWidget *window, *button;
	/* 새로운 Application 윈도우 생성 타이틀과 크기 설정 */
	window = gtk_application_window_new (app);
	gtk_window_set_title (GTK_WINDOW (window), "Window");
	gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
	/* “Hello World” 라는 라벨을 가진 버튼 생성 */
	button = gtk_button_new_with_label ("Hello World");
	/* 버튼의 clicked 시그널과 destroy 콜백함수를 연결 */
	g_signal_connect (button, "clicked",G_CALLBACK (destroy), NULL);
	/* 버튼을 gtk 컨테이너 위젯인 윈도우에 패킹함 */
	gtk_container_add (GTK_CONTAINER (window), button);
	/* 생성한 모든 위젯들을 화면에 표시 */
	gtk_widget_show_all (window);
}
int main(int argc, char *argv[])
{
	GtkApplication *app;
	int status;
	app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);
	gtk_main ();
	return 0;
}



