dir = "#{ARGV[0]}/"

raise "provide base directory as first argument" if dir == nil

dir = "#{Dir.getwd}/#{dir}" if dir[0] != '/'

dir.gsub!(/\\\\/, '')

puts "dir: #{dir}"

cpp_file = nil
if dir.match?(/.cpp$/)
  cpp_file = dir.split('/')[dir.split('/').length - 1]
else
  all_cpp_files = Dir.glob("#{dir}*.cpp")
  if all_cpp_files.length == 1
    cpp_file = all_cpp_files.first
  elsif all_cpp_files.length == 0
    raise "No cpp files found in directory #{dir}"
  else
    raise "Too many cpp files in dir. Select one between \n#{all_cpp_files.join("\n")}"
  end
end

puts "cpp_file: #{cpp_file}"

