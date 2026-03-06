package Atividade3;

public class DataTeste {
    public static void main(String[] args) {
        Data data = new Data(13, 05, 2024);

        System.out.println("Data: "); 
        data.DisplayData();

        data.setDia(14);

        System.out.println("Data corrigida: ");
        data.DisplayData();
    }
}
