Genome::Genome(
	unsigned __int64 genome,
	unsigned __int8 genome_size,
	unsigned __int8 args, 
	unsigned __int64 generation, 
	unsigned __int8 mutationChance
)
	: genome(genome)
	, genome_size(genome_size > 64 ? 64 : genome_size)
	, props(0)
	, args(args)
	, cursor(0)
	, generation(generation)
	, replicate_cost(0)
	, mutationChance(mutationChance)
	, ration({ 0, 0, 0 })
	, species({ 0, 0, 0 })
{
	Construct();
}