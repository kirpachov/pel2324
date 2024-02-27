# Copying from solution.cpp

require 'byebug'

def get_right_set(set, treshold)
  res = []
  j = set.size - 1
  # puts "get_right_set | set: #{set}"
  (set.size - 1).downto(0) do |i|
    # puts "get_right_set | i: #{i}, j: #{j}, set[i]: #{set[i]}, set[j]: #{set[j]}"

    while j >= 0 && set[j] - set[i] > treshold
      # puts "j -= 1"
      j -= 1
    end

    res[i] = j
  end

  res
end

# Ritorna un array di interi.
# L'indice si riferisce all'indice del set passato come parametro.
# Il valore indica da quale indice si può iniziare per fare un set che sia valido
#
# Esempio: [0, 0, 2, 2, 2, 5, 5, 5, 5, 9, 10]
# All'indice 0 troviamo lo 0. Il che significa che partendo dall'indice 0 possiamo formare un set di 1 elementi, dall'elemento 0 all'elemento 0.
# All'indice 1 troviamo lo 0. Indica che possiamo formare un set con tutti gli elementi dall'indice 0, quindi due elementi. L'elemento 0 e l'elemento 1.
# All'indice 3 troviamo il 2 perché il suo set sinistro inizia dall'indice due.
#
# Più un indice di partenza si ripete e più sono grandi i set che si possono formare.
def get_left_set(set, treshold)
  res = []
  j = 0
  # puts "get_left_set | set: #{set}"
  0..set.size.times do |i|
    # puts "get_left_set | i: #{i}, j: #{j}, set[i]: #{set[i]}, set[j]: #{set[j]}"
    while j < set.size && set[i] - set[j] > treshold
      # puts "j += 1"
      j += 1
    end

    res[i] = j
  end

  res
end

def find_subsets(treshold, set)
  set.sort!
  right_set = get_right_set(set, treshold)
  left_set = get_left_set(set, treshold)

  ls = set.map { 0 }
  (set.size - 1).downto(0) do |i|
    ls[i] = i - left_set[i] + 1

    ls[i] = [ls[i], ls[i - 1]].max if i > 0
  end

  rs = set.map { 0 }
  (set.size - 1).downto(0) do |i|
    rs[i] = right_set[i] - i + 1

    rs[i] = [rs[i], rs[i + 1]].max if i < set.size - 1
  end

  # puts "set: #{set}"
  # puts "left_set: #{left_set}"
  # puts "ls: #{ls}"
  # puts "\n\n"
  # puts "set:\t" + set.map{|n| "\t#{n}"}.join(', ')
  # puts "lefts:\t#{left_set.map{|n| "\t#{n}"}.join(', ')}"
  # puts "ls:\t   #{ls.map{|n| "\t#{n}"}.join(', ')}"
  #
  # puts "\n\n"
  # puts "set:\t" + set.map{|n| "\t#{n}"}.join(', ')
  # puts "rights:\t#{right_set.map{|n| "\t#{n}"}.join(', ')}"
  # puts "rs:\t   #{rs.map{|n| "\t#{n}"}.join(', ')}"

  ans = 0
  (0..(set.size - 2)).each do |i|
    # puts "ans | i: #{i}, ls[i]: #{ls[i]}, rs[i + 1]: #{rs[i + 1]}"
    ans = [ans, ls[i] + rs[i + 1]].max
  end

  ans
end

# def main
#   cases_count = gets.to_i
#   while cases_count > 0
#     numbers_current_case, treshold = gets.split.map(&:to_i)
#     set = gets.split(' ').map(&:to_i)
#
#     puts find_subsets(treshold, set)
#     cases_count -= 1
#   end
# end

def main
  [
    {
      treshold: 500,
      set: [1598, 2672, 660, 1864, 1672, 2942, 1075, 4744, 3685, 2893, 2777]
    }
  ].each do |scenario|
    puts find_subsets(scenario[:treshold], scenario[:set])
  end

end

main