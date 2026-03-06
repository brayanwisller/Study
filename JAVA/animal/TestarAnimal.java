public class TestarAnimal {
    public static void main(String[] args) {
        Mamifero Camelo = new Mamifero("Camelo", 150, 4, "Amarelo", "Terra", 2.0, "Leite");

        Peixe Tubarão = new Peixe("Tilapia", 20, 0, "Cinzento", "Mar", 1.5, "Cauda");

        Mamifero UrsoCanada = new Mamifero("Urso-do-Canadá", 180, 4, "Vermelho", "Terra", 0.5, "Mel");

        System.out.println(Camelo.toString());
        System.out.println(Tubarão.toString2());
        System.out.println(UrsoCanada.toString());
    }
}
