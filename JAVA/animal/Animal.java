public class Animal {
    private String nome;
    private double comprimento;
    private int numPatas;
    private String cor;
    private String ambiente;
    private double velocidadeMedia;

    public Animal(String nome, double comprimento, int numPatas, String cor, String ambiente, double velocidadeMedia){
        this.nome = nome;
        this.comprimento = comprimento;
        this.numPatas = numPatas;
        this.cor = cor;
        this.ambiente = ambiente;
        this.velocidadeMedia = velocidadeMedia;
    }

    public void setNome(String nome){
        this.nome = nome;
    }
    public String getNome(){
        return nome;
    }
    public void setComprimento(double comprimento){
        this.comprimento = comprimento;
    }
    public double getComprimento(){
        return comprimento;
    }
    public void setNumPatas(int numPatas){
        this.numPatas = numPatas;
    }
    public int getNumPatas(){
        return numPatas;
    }
    public void setCor(String cor){
        this.cor = cor;
    }
    public String getCor(){
        return cor;
    }
    public void setAmbiente(String ambiente){
        this.ambiente = ambiente;
    }
    public String getAmbiente(){
        return ambiente;
    }
    public void setVelocidadeMedia(double velocidadeMedia){
        this.velocidadeMedia = velocidadeMedia;
    }
    public double getVelocidadeMedia(){
        return velocidadeMedia;
    }

    public String toString1(){
        return "Animal {" +
        "nome: " + nome +
        ", comprimento: " + comprimento +
        ", número de patas: " + numPatas +
        ", cor: " + cor  +
        ", ambiente: " + ambiente +
        ", velocidade media: " + velocidadeMedia;
    }
}