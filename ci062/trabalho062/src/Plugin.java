import java.io.*;
public class Plugin
{
	//Vari�veis
	protected String classe;
	protected String[] pontoExtensao; //O que plugar
	protected String[] extensao; //Onde plugar
	protected String instanciado; //indica se o plugin est� instanciado
	protected String plug; //Plugin onde o plugin est� plugado o.�
	protected String[] plugados; //Array de plugs plugados no plugin o.�
	protected int numPlugados; //N�mero de plugins plugados
	
	//Vari�veis Auxiliares
	int count = 1;
	String arg;

	//M�todo Construtor
	public Plugin()
	{
		this.instanciado = "N";
		this.numPlugados = 0;
	}
	//Pega nome da classe do Arquivo
	public void CarregaPlugin(String arq) throws IOException
	{
		BufferedReader br = new BufferedReader(new FileReader(arq + ".txt"));
		if (br.ready())
			this.classe = br.readLine().substring(6); //L� primeira linha do arquivo
		try 
		{
			while(br.ready()) //L� o arquivo enquanto existir linhas
			{
				arg = br.readLine();
				if (arg.substring(0, 14).equals("ponto.extensao="))
				{
					this.pontoExtensao[count] = arg.substring(15);
				}
				else if (arg.substring(0, 9).equals("extensao="))
				{
					this.extensao[count] = arg.substring(10);
				}
			}
			br.close();
		}
		catch (EOFException eofe) //Detecta end of file
		{
		}
		catch (IOException ioe) //Detecta outras exce��es n�o previstas e imprime
		{
			System.out.println(ioe); 
		}
	}
	
	//Pluga
	public void Pluga(Plugin plugar, int i, int j) throws IOException
	{
		File saida = new File("./saida.txt");
		FileWriter fw = new FileWriter(saida, true);
		BufferedWriter bw = new BufferedWriter(fw);
		if (plugar.instanciado.equals("S")) //S� pluga se o plugin onde plugar j� estiver instanciado
		{
			this.instanciado = "S"; //Muda o status do plugin
			this.plug = plugar.classe; 
			plugar.numPlugados = plugar.numPlugados + 1; //Aumenta o n�mero de plugins plugados no plugin de origem
			plugar.plugados[plugar.numPlugados] = this.classe; //Pluga no plugin de origem
			try 
			{
				bw.write(this.classe + "(" + i + ") plugado em" + plugar.classe + "(" + j + ")");
			}
			catch (IOException ioe) //Detecta outras exce��es n�o previstas e imprime
			{
				System.out.println(ioe); 
			}
		}
		else
		{
			try
			{
				bw.write("ERRO: Plugin" + plugar.classe + "(" + i + ") n�o instanciado.");
			}
			catch (IOException ioe) //Detecta outras exce��es n�o previstas e imprime
			{
				System.out.println(ioe); 
			}
		}
	}
	
	//Getters
	public String GetClasse() 
	{
		return this.classe;
	}
}
