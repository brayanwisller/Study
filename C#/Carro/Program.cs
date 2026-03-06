using System.ComponentModel.DataAnnotations;

class Carro{
    private string marca = "";
    private string modelo = "";
    private int anoFabricacao = 0;

    public Carro(string marca, string modelo, int anoFabricacao){
        this.marca = marca;
        this.modelo = modelo;
        this.anoFabricacao = anoFabricacao;
    }

    public void Ligar(){
        Console.WriteLine($"{marca} {modelo} fabricado em {anoFabricacao} está ligado");
    }

    public void setMarca(string marca){
        if(marca != null){
            marca = this.marca;
        }
    }

    public void setModelo(string modelo){
        if(modelo != null){
            modelo = this.modelo;
        }
    }

    public void setAnoFabricacao(int anoFabricacao){
        if(anoFabricacao != 0){
            anoFabricacao = this.anoFabricacao;
        }
    }

    public string getMarca(){
        return marca;
    }

    public string getModelo(){
        return modelo;
    }

    public int getAnoFabricacao(){
        return anoFabricacao;
    }
}

class Program2{
    public static void Main(string[] args){
        Carro carro_1 = new Carro("Honda", "Civic", 2017);

        carro_1.Ligar();
        
        carro_1.setMarca("Chevrolet");
        carro_1.setModelo("Onix");
        carro_1.setAnoFabricacao(2016);
        
        carro_1.Ligar();
    }
}