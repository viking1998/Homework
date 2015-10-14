require 'csv'

def sort? command
  command == "sort"
end

def asc? option_2
  option_2 == "ASC"
end

def column_contains_num? option_1
  option_1 == "2"
end

def desc? option_2
  option_2 == "DESC"
end

def filter_costs? command
  command == "filter_costs"
end

CSV.open("result.csv","w") do |csv_array|
  csv_array << ["Qbulki", "2010-04-10", "10"]
  csv_array << ["Banani", "2014-09-20", "8"]
  csv_array << ["Qgodi", "2009-01-30", "9"]
  csv_array << ["Malinki", "2010-04-12", "15"]
end

command = ARGV[0]
option_1 = ARGV[1]
option_2 = ARGV[2]

my_csv = CSV.read 'result.csv'
if sort? command
  column_number = option_1.to_i
  if asc? option_2
    my_csv.sort! { |a,b| if column_contains_num? option_1 
                           a[column_number].to_i <=> b[column_number].to_i 
                         else a[column_number] <=> b[column_number] 
                         end}
  elsif desc? option_2
    my_csv.sort! { |a,b| if column_contains_num? option_1  
                           b[column_number].to_i <=> a[column_number].to_i 
                         else b[column_number] <=> a[column_number] 
                         end}
  end
elsif filter_costs? command
  if option_1.to_i < option_2.to_i
    my_csv.sort_by! { |item_cost| item_cost[2].to_i}
    my_csv.delete_if { |a| a[2].to_i < option_1.to_i || a[2].to_i > option_2.to_i}
  else
    print "The first option is min_value the second - max_value!"
  end
end

CSV.open("result.csv","w") do |csv_row|
  my_csv.each do |my_row|
    csv_row << my_row
  end
end

