package Atividade1;

public class testarfatura {
    public static void main(String[] args){
        fatura fatura1 = new fatura("102030", "teclado", 20, -250.00);
        System.out.println("TOTAL DA FATURA: " + fatura1.getTotalFatura());
        fatura1.setPreço(220.00);
        System.out.println("Total da Fatura = " + fatura1.getTotalFatura());
    }
}
