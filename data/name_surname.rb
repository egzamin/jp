require 'faker' # v1.6.3

10_000.times do
  puts "#{Faker::Name.first_name} #{Faker::Name.last_name}"
end
