public class Produto {
    String nome;
    double preço;

    void informarNome(){
        System.out.println("O nome do produto é: " + nome);
    }

    void informarPreço(){
        System.out.println("O preço do produto é: " + preço);
    }

    void fazerPromoçao(){
        preço = preço - 1;
    }
}