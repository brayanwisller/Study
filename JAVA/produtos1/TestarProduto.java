public class TestarProduto {
    public static void main (String[] args){
        Produto newProduto;
        newProduto = new Produto();

        newProduto.nome = "Notebook Samsung";
        newProduto.preço = 3100;

        newProduto.informarNome();
        newProduto.informarPreço();

        newProduto.fazerPromoçao();
        newProduto.informarPreço();
    }
}