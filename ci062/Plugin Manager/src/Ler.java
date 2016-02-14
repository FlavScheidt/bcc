public class Ler 
{
	public static int RetornaPosicao(int argsLength, Plugin[] pluginList, String plugar)
	{
		for (int k = 1; k < argsLength; k++)
		{
			if (pluginList[k].equals(plugar))
			{
					return k;
			}
		}
		return -1;
	}
}
