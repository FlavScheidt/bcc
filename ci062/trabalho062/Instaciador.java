import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Instaciador 
{
	static Plugin[] pluginList;
	private static InputStreamReader stdin = new InputStreamReader(System.in);
	private static BufferedReader terminal = new BufferedReader(stdin);
	static String plugar;
	static String plug;
	private static int pos;
	private static int pos2;
	private static String aux;
	
	public static void main (String args[]) throws IOException
	{
		try
		{
			aux = terminal.readLine().trim();
		}
		catch (IOException ioe) //Detecta outras exceções não previstas e imprime
		{
			System.out.println(ioe); 
		}
		while(!aux.equals("Please, exit!"))
		{
			//Carrega Plugins e Instancia o Primeiro, que deve ser o framework
			for (int i = 0; i < args.length; i++)
			{
				try
				{
					pluginList[i] = new Plugin();
					pluginList[i].CarregaPlugin(args[i]);
					if (i == 0)
						pluginList[i].instanciado = "S";
				}
				catch (IOException ioe) //Detecta outras exceções não previstas e imprime
				{
					System.out.println(ioe); 
				}
			}
			
			//Nome da classe a ser plugada
			System.out.println("Digite o nome da classe a ser plugada");
			try
			{
				plugar = terminal.readLine().trim();
			}
			catch (IOException ioe) //Detecta outras exceções não previstas e imprime
			{
				System.out.println(ioe); 
			}
			System.out.println("Digite o nome da classe onde plugar");
			try
			{
				plug = terminal.readLine().trim();
			}
			catch (IOException ioe) //Detecta outras exceções não previstas e imprime
			{
				System.out.println(ioe); 
			}
			pos = Ler.RetornaPosicao(args.length, pluginList, plugar); //Procura a posição de plugar no vetor
			pos2 = Ler.RetornaPosicao(args.length, pluginList, plug); //Procura a posição de plug no vetor
			if ((pos != -1) || (pos2 != -1)) //Valores negativos indicam que o plugin não existe
			{
				pluginList[pos].Pluga(pluginList[pos2], pos, pos2);
			}
			else
			{
				System.out.println("ERRO: O plugin referenciado não existe.");
			}
			try
			{
				aux = terminal.readLine().trim();
			}
			catch (IOException ioe) //Detecta outras exceções não previstas e imprime
			{
				System.out.println(ioe); 
			}
		}
	}
}
